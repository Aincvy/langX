#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include "Object.h"
#include "ExecNode.h"
#include "langX.h"
#include "Function.h"
#include "Allocator.h"
#include "NodeCreator.h"
#include "ClassInfo.h"
#include "Environment.h"
#include "NullObject.h"
#include "langXThread.h"
#include "LogManager.h"
#include "langXObject.h"
#include "langXCommon.h"
#include "Number.h"


extern void deal_state(langX::NodeState * state);

void resetNodeState(langX::Node *n) {
	deal_state(&n->state);
	if (n->value != NULL)
	{
		langX::Allocator::free(n->value);
		n->value = NULL;
	}
	// ptr_u 可能存放了参数， 等以后有问题的时候再进行调整，  0821
	//n->ptr_u = NULL;
	n->postposition = NULL;
	/*n->state.in_func = true;*/

	if (n->type == langX::NODE_OPERATOR)
	{
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			langX::Node *t = n->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}

			resetNodeState(t);
		}
	}
}

// 设置节点的状态为 可释放 [暂时没用到这个函数]
void setStateToCanFree(langX::Node *n) {
	//deal_state(&n->state);
	//deal_switch_info(&n->switch_info);
	n->freeOnExecuted = true;

	if (n->type == langX::NODE_OPERATOR)
	{
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			langX::Node *t = n->opr_obj->op[i];
			if (t == nullptr)
			{
				continue;
			}

			setStateToCanFree(t);
		}
	}
}

namespace langX {

    // 实例化 空参数指针
    X3rdArgs *emptyArgs = {};

    // Function  以及相关的类实现

	Function::Function()
	{
	}

	Function::Function(Node *root)
	{
		this->m_node_root = root;
	}

	Function::Function(const char *name, Node *node)
	{
		setName(name);
		this->m_node_root = node;
	}

	Function::~Function()
	{
		if (this->m_name != NULL)
		{
			free(this->m_name);
			this->m_name = NULL;
		}
		if (this->m_node_root != NULL)
		{
			//this->m_node_root->freeOnExecuted = true;
			setStateToCanFree(this->m_node_root);
			freeNode(this->m_node_root);
			this->m_node_root = NULL;
		}

		// todo  参数列表

	}

	const char * Function::getName() const
	{
		return this->m_name;
	}

	void Function::setName(const char *name)
	{
		if (this->m_name != NULL)
		{
			free(this->m_name);
			this->m_name = NULL;
		}
		this->m_name = strdup(name);
	}

	void Function::setParamsList(ParamsList *list)
	{
		this->m_params_list = list;
	}

	ClassInfo * Function::getClassInfo() const
	{
		return this->m_class_info;
	}

	void Function::setClassInfo(ClassInfo *a)
	{
		this->m_class_info = a;
	}

	ParamsList * Function::getParamsList() const
	{
		return this->m_params_list;
	}

	int Function::getArgsCount() const
	{
		return 0;
	}

	Object * Function::call() const
	{
		if (m_node_root == nullptr)
		{
			return nullptr;
		}

		resetNodeState(this->m_node_root);

		langXThread *thread = getState()->curThread();
		Node *lastFuncCallRoot = thread->getFuncRootNode();
		thread->setInFunction(true);
		thread->setFuncRootNode(this->m_node_root);
		thread->beginExecute(this->m_node_root, true);
		execNodeButLimit(nullptr, this->m_node_root);
		thread->setInFunction(false);
		thread->setFuncRootNode(lastFuncCallRoot);

		if (m_node_root->value != nullptr)
		{
			Allocator::free(m_node_root->value);
			m_node_root->value = nullptr;
		}

		Object * tmp = thread->getFunctionResult();

		return tmp == nullptr ? tmp : tmp->clone();
	}

	bool Function::is3rd() const
	{
		return false;
	}

	bool Function::hasName() const
	{
		if (m_name == nullptr || strcmp(this->m_name, "") == 0)
		{
			return false;
		}
		return true;
	}

	void Function::setScriptEnv(ScriptEnvironment *env)
	{
		this->m_script_env = env;
	}

	ScriptEnvironment * Function::getScriptEnv() const
	{
		return this->m_script_env;
	}

	X3rdFunction::X3rdFunction()
	{
		m_worker = NULL;
		m_state = NULL;
	}

	X3rdFunction::~X3rdFunction()
	{
	}

	void X3rdFunction::setLangX(langXState *x)
	{
		this->m_state = x;
	}

	langXState * X3rdFunction::getLangX() const
	{
		return this->m_state;
	}

	void X3rdFunction::setWorker(X3rdFuncWorker worker)
	{
		this->m_worker = worker;
	}

	X3rdFuncWorker X3rdFunction::getWorker() const
	{
		return this->m_worker;
	}

	bool X3rdFunction::is3rd() const
	{
		return true;
	}

	Object * X3rdFunction::call(const X3rdArgs & args)
	{
		if (!m_worker)
		{
			// error function.
			logger->error("error function: %s!", this->getName());
			return nullptr;
		}

		return m_worker(this, args);
	}

    Object *X3rdFunction::call(X3rdArgs *args) {
        return call(*args);
    }

    FunctionRef::FunctionRef(Function * f)
	{
		this->m_func = f;
	}

	FunctionRef::~FunctionRef()
	{
	}

	bool FunctionRef::isTrue() const
	{
		if (this->m_func == NULL)
		{
			return false;
		}
		return true;
	}

	ObjectType FunctionRef::getType() const
	{
		return FUNCTION;
	}

	Object * FunctionRef::clone() const
	{
		FunctionRef * r = new FunctionRef(this->m_func);
		if (this->m_func_class != NULL)
		{
            r->setClassInfo(this->m_func_class);
		}
		else if (this->m_func_obj != NULL)
		{
            r->setObject(this->m_func_obj);
		}
		r->setEmergeEnv(getEmergeEnv());
		r->setCharacteristic(characteristic());
		r->setLocal(this->isLocal());
		r->setConst(this->isConst());
		r->setName(this->getName());

		return r;
	}

	void FunctionRef::update(Object * a)
	{
		if (a->getType() != FUNCTION)
		{
			return;
		}

		FunctionRef *f = (FunctionRef*)a;
		this->m_func = f->getRefFunction();
		if (f->getClassInfo() != NULL)
		{
			this->m_func_class = f->getClassInfo();
		}
		else if (f->getObject() != NULL)
		{
			this->m_func_obj = f->getObject();
		}
	}

	Function * FunctionRef::getRefFunction()
	{
		return this->m_func;
	}

	langXObject * FunctionRef::getObject() const
	{
		return this->m_func_obj;
	}

	void FunctionRef::setObject(langXObject *a)
	{
		this->m_func_obj = a;
	}

	ClassInfo * FunctionRef::getClassInfo() const
	{
		return this->m_func_class;
	}

	void FunctionRef::setClassInfo(ClassInfo *a)
	{
		this->m_func_class = a;
	}

	Environment * FunctionRef::getFunctionEnv()
	{
		if (this->m_func_class != NULL)
		{
			return new ClassBridgeEnv(this->m_func_class);
		}
		else if (this->m_func_obj != NULL)
		{
			return new ObjectBridgeEnv(this->m_func_obj);
		}
		return nullptr;
	}

	Object * FunctionRef::call(ArgsList * argsList, const char * remark )
	{

		return nullptr;
	}

	Object * FunctionRef::call(Object* args[], int len, const char * remark)
	{
		Function *function = this->m_func;
		Object * ret = NULL;

		langXThread * thread = getState()->curThread();
		thread->getStackTrace().newFrame(function->getClassInfo(), function, remark);

		if (function->is3rd())
		{
			// 第三方函数
			X3rdFunction *x3rdfunc = (X3rdFunction*)function;
			X3rdArgs _3rdArgs;
			memset(&_3rdArgs, 0, sizeof(X3rdArgs));
			if (args != NULL)
			{
				for (int i = 0; i < len; i++)
				{
					if (args[i] == NULL)
					{
						_3rdArgs.args[i] = NULL;
						continue;
					}

					_3rdArgs.args[i] = args[i]->clone();
				}
				_3rdArgs.index = len;
			}

			_3rdArgs.object = this->m_func_obj;

			ret = x3rdfunc->call(_3rdArgs);
		}
		else {
			// 当前引用指向的那个环境
			Environment *tEnv = getFunctionEnv();
			if (tEnv != nullptr)
			{
				getState()->curThread()->newEnv(tEnv);
			}

			// 函数执行的环境
			Environment * env = getState()->curThread()->newEnv();

			if (args != NULL)
			{
				XParamsList *params = function->getParamsList();
				for (int i = 0; i < len; i++)
				{
					if (i >= params->index)
					{
						break;
					}

					if (args[i])
					{
						env->putObject(params->args[i], args[i]);
					}
					else {
						NullObject nullobj;
						env->putObject(params->args[i], &nullobj);
					}
				}
			}

			ret = function->call();
			//printf("call function %s over in function ref." ,this->m_func->getName());
			getState()->curThread()->backEnv();

			if (tEnv != NULL)
			{
				getState()->curThread()->backEnv();
			}
		}

		thread->getStackTrace().popFrame();

		return ret;
	}

	void FunctionRef::finalize()
	{
	}



    void copyArgsTo3rdArgs(ArgsList *args, X3rdArgs *_3rdArgs, langXObject *object){
        memset(_3rdArgs, 0 , sizeof(X3rdArgs));
        _3rdArgs->object = object;

        // 转换参数
        if (args != nullptr) {
            _3rdArgs->index = args->index;

            for (int i = 0; i < args->index; ++i) {
                _3rdArgs->args[i] = args->args[i]->value;
            }
        }
    }


    // 添加函数的拓展变量到 函数内部 | $_, $1,$2 等
    void addFunctionExtendsVar(Environment* env, X3rdArgs* args){
        if (!env->hasObject(FE_KEY_VARIABLE_COUNT)){
            auto functionArgsCount = args == nullptr ? 0 : args->index;
            env->putObject(FE_KEY_VARIABLE_COUNT , Allocator::allocateNumber(functionArgsCount));

//         赋值给 $1,$2..
            for (int i = 0; i < functionArgsCount; ++i) {
                std::stringstream  ss;
                ss << FE_KEY_VARIABLE_PREFIX;
                ss << (i + 1);
                const std::string & tmpVarName = ss.str();

                if (!env->hasObject(tmpVarName)){
                    // 不包含这个变量， 则赋值
                    env->putObject(tmpVarName, args->args[i]);
                }
            }
        }
    }


    /**
     * 真正的执行函数的逻辑内容
     * @param thread
     * @param function
     * @param args
     * @return
     */
	Object *realCallFunction(langXThread *thread, Function *function, X3rdArgs *args){
	    // 补偿参数

        // 判断和执行第三方函数
        if (function->is3rd()) {
            return ((X3rdFunction *) function)->call(args);
        }

        // 执行普通的节点函数
        DefaultEnvironment env;

        // 整理参数
        auto params = function->getParamsList();
        if (params != nullptr) {

            NullObject nullObj;

            // put real args value
            for (int i = 0; i < args->index; i++)
            {
                // 如果给出的参数个数大于需要的参数个数， 则无视剩余给出的参数
                if (i >= params->index)
                {
                    break;
                }

                auto tmp = args->args[i];
                auto name = params->args[i];

                env.putObject(name, tmp);
            }
        }

        // 添加前缀属性
        addFunctionExtendsVar(&env, args);

        // 设置环境， 执行函数
        thread->newEnv(&env);
        auto result = function->call();
        thread->backEnv(false);

        return result;
	}


    Object *callFunction(Function *function, X3rdArgs *args, const char *remark){
        return callFunction(getState()->curThread(), function, args, remark);
	}

    Object *callFunction(Function *function, const char *remark){
	    X3rdArgs _3rdArgs;
	    _3rdArgs.index = 0;
	    _3rdArgs.object = nullptr;

	    callFunction(function, &_3rdArgs, remark);
	}

    Object *callFunction(langXThread *thread, Function *function, X3rdArgs *args, const char *remark) {
        if (function == nullptr) {
            return nullptr;
        }

        auto & stackTrace = thread->getStackTrace();

        // 执行层次入栈
        stackTrace.newFrame(function, remark);
        thread->setInFunction(true);

        auto result = realCallFunction(thread, function, args);
        thread->setFunctionResult(result);

        // 执行层次 出栈
        stackTrace.popFrame();
        thread->setInFunction(false);

        return result;
    }

    Object *callFunction(langXThread *thread, Function *function, ArgsList *args, const char *remark){
        return callFunction(thread, function, args, nullptr, remark);
	}

    Object *callFunction(langXThread *thread, Function *function, ArgsList *args, langXObject *object, const char *remark) {
	    // 转换 args 变成 3rdArgs
	    X3rdArgs _3rdArgs;
        copyArgsTo3rdArgs(args, &_3rdArgs, object);

        // 进入 对象环境
        auto env = object == nullptr ? nullptr : object->getObjectEnvironment();
        if (env != nullptr) {
            thread->newEnvByBridge(env);
        }

        // 执行函数逻辑
        auto result = callFunction(thread, function, &_3rdArgs, remark);

        // 退出对象环境
        if (env != nullptr) {
            thread->backEnv();
        }

        return result;
    }


    Object *callFunction(langXThread *thread, FunctionRef *functionRef, X3rdArgs *args, const char *remark) {

	    // 函数执行需要的 环境
	    auto env = functionRef->getFunctionEnv();
        if (env != nullptr) {
            thread->newEnv(env);
        }

        // 执行函数
        auto result = callFunction(thread, functionRef->getRefFunction(), args, remark);

        // 环境退回
        if (env != nullptr) {
            thread->backEnv();
        }

        return result;
    }

    Object *callFunction(langXThread *thread, FunctionRef *functionRef, ArgsList *args, const char *remark){
        // 转换 args 变成 3rdArgs
        X3rdArgs _3rdArgs;
        copyArgsTo3rdArgs(args, &_3rdArgs, functionRef->getObject());

        return callFunction(thread, functionRef, &_3rdArgs, remark);
    }



}