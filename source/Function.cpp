#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include "../include/Object.h"
#include "../include/ExecNode.h"
#include "../include/langX.h"
#include "../include/Function.h"
#include "../include/Allocator.h"
#include "../include/YLlangX.h"
#include "../include/ClassInfo.h"
#include "../include/Environment.h"
#include "../include/NullObject.h"


langX::Allocator m_exec_alloc;
extern void deal_state(langX::NodeState * state);
extern void deal_switch_info(langX::SwitchInfo *si);

void resetNodeState(langX::Node *n) {
	deal_state(&n->state);
	deal_switch_info(&n->switch_info);
	if (n->value != NULL)
	{
		m_exec_alloc.free(n->value);
		n->value = NULL;
	}
	// ptr_u 可能存放了参数， 等以后有问题的时候再进行调整，  0821
	//n->ptr_u = NULL;
	n->postposition = NULL;
	n->state.in_func = true;

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
	deal_state(&n->state);
	deal_switch_info(&n->switch_info);
	n->freeOnExeced = true;

	if (n->type == langX::NODE_OPERATOR)
	{
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			langX::Node *t = n->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}

			setStateToCanFree(t);
		}
	}
}

namespace langX {

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
			this->m_node_root->freeOnExeced = true;
			freeNode(this->m_node_root);
			this->m_node_root = NULL;
		}
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
			return NULL;
		}

		resetNodeState(this->m_node_root);

		//m_node_root->state.in_func = true;
		__execNode(m_node_root);

		if (m_node_root->value != NULL)
		{
			Object * obj = m_node_root->value->clone();
			m_exec_alloc.free(m_node_root->value);
			m_node_root->value = NULL;
			return obj;
		}
		return nullptr;
	}


	bool Function::is3rd() const
	{
		return false;
	}

	bool Function::hasName() const
	{
		if (strcmp(this->m_name, "") == 0)
		{
			return false;
		}
		return true;
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
			printf("error function: %s!\n", this->getName());
			return nullptr;
		}
		return m_worker(this, args);
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
		if (this->m_func_claxx != NULL)
		{
			r->setClaxx(this->m_func_claxx);
		}
		else if (this->m_func_obj != NULL)
		{
			r->setObj(this->m_func_obj);
		}
		r->setEmergeEnv(getEmergeEnv());
		r->setCharacteristic(characteristic());

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
		if (f->getClaxx() != NULL)
		{
			this->m_func_claxx = f->getClaxx();
		}
		else if (f->getObj() != NULL)
		{
			this->m_func_obj = f->getObj();
		}
	}

	Function * FunctionRef::getRefFunction()
	{
		return this->m_func;
	}

	langXObject * FunctionRef::getObj() const
	{
		return this->m_func_obj;
	}

	void FunctionRef::setObj(langXObject *a)
	{
		this->m_func_obj = a;
	}

	ClassInfo * FunctionRef::getClaxx() const
	{
		return this->m_func_claxx;
	}

	void FunctionRef::setClaxx(ClassInfo *a)
	{
		this->m_func_claxx = a;
	}

	Environment * FunctionRef::getFunctionEnv()
	{
		if (this->m_func_claxx != NULL)
		{
			return new ClassBridgeEnv(this->m_func_claxx);
		}
		else if (this->m_func_obj != NULL)
		{
			return new ObjectBridgeEnv(this->m_func_obj);
		}
		return nullptr;
	}

	Object * FunctionRef::call(ArgsList * argsList, const char * remark)
	{
		Environment *env = getFunctionEnv();
		if (env != NULL)
		{
			getState()->newEnv(env);
		}
		Object *ret = callFunc(getRefFunction(), argsList, remark);
		if (env != NULL)
		{
			getState()->backEnv();
		}

		return ret;
	}

	Object * FunctionRef::call(Object* args[], int len, const char * remark)
	{
		//Environment *env = getFunctionEnv();
		Function *function = this->m_func;
		Object * ret = NULL;

		getState()->getStackTrace().newFrame(function->getClassInfo(), function, remark);

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
			//Environment *currEnv1 = getState()->getCurrentEnv();
			Environment *currEnv1 = getFunctionEnv();
			if (currEnv1->isObjectEnvironment())
			{
				if (currEnv1->isEnvEnvironment())
				{
					_3rdArgs.object = ((ObjectBridgeEnv*)((EnvironmentBridgeEnv*)currEnv1)->getBridgeEnv())->getEnvObject();
				}
				else {
					_3rdArgs.object = ((ObjectBridgeEnv*)currEnv1)->getEnvObject();
				}


			}

			ret = x3rdfunc->call(_3rdArgs);
		}
		else {
			
			Environment * env = getState()->newEnv();

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
			if (env != NULL)
			{
				getState()->backEnv();
			}
		}
		

		getState()->getStackTrace().popFrame();

		return ret;
	}

	void FunctionRef::finalize()
	{

	}

}