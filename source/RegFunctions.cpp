#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>

#ifdef WIN32
#else
#include <unistd.h>
#include <termios.h>
#include <sys/stat.h>
#endif

#include "RegFunctions.h"
#include "StringType.h"
#include "Number.h"
#include "NodeCreator.h"
#include "langXThread.h"
#include "ClassInfo.h"
#include "NullObject.h"
#include "langXObject.h"
#include "Allocator.h"
#include "XArray.h"
#include "TypeHelper.h"

static struct termios old, newone;

namespace langX {

	/* Initialize new terminal i/o settings */
	void initTermios(int echo)
#ifdef WIN32
	{
		// win32
	}
#else
	{
		tcgetattr(0, &old); /* grab old terminal i/o settings */
		newone = old; /* make new settings same as old settings */
		newone.c_lflag &= ~ICANON; /* disable buffered i/o */
		newone.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
		tcsetattr(0, TCSANOW, &newone); /* use these new terminal i/o settings now */
	}
#endif

	/* Restore old terminal i/o settings */
	void resetTermios(void)
#ifdef WIN32
	{
		// win32
	}
#else
	{
		tcsetattr(0, TCSANOW, &old);
	}
#endif

	// 注册一些类到 langX里面
	// 基本上都是 本文件里面需要用到的类
	void regClasses(langXState *state) {
		c_metadata = new ClassInfo("ObjectMetadata");
		NullObject nullObj;
		c_metadata->addMember("memoryAddress", &nullObj);
		c_metadata->addMember("variableName", &nullObj);
		c_metadata->addMember("characteristic", &nullObj);
		c_metadata->addMember("emergeEnv", &nullObj);
		c_metadata->addMember("value", &nullObj);
		state->regClassToGlobal(c_metadata);

		c_empty_class = new ClassInfo("EmptyClass");
		state->regClassToGlobal(c_empty_class);
	}

	// c printf 函数 的桥接
	Object * langX_print(X3rdFunction *func, const X3rdArgs & args) {
		if (args.index <= 0)
		{
			return nullptr;
		}

		for (size_t i = 0; i < args.index; i++)
		{
			Object *obj = args.args[i];

			if (obj == NULL || obj->getType() == NULLOBJECT)
			{
				printf("null");
			}
			else if (obj->getType() == STRING)
			{
				String * str = (String*)obj;

				printf("%s",str->getValue());
			}
			else if (obj->getType() == NUMBER)
			{
				printf("%f", ((Number*)obj)->getDoubleValue());
			}

			else if (obj->getType() == OBJECT)
			{
				char buf[2048] = {0 };
				objToString(obj, buf, 0, 2048);
				printf("%s", buf);
			}
		}

		return nullptr;
	}

    // 打印语句之后自动换行
    Object * langX_println(X3rdFunction *func, const X3rdArgs & args) {
        langX_print(func, args);
        printf("\n");

        return nullptr;
    }

	//  c system 函数的桥接
	Object * langX_system_run(X3rdFunction *func, const X3rdArgs & args) {
		if (args.index <= 0)
		{
			printf("function %s need at least 1 param!\n", func->getName());
			return NULL;
		}

		// 先试试单参数
		Object *obj = args.args[0];
		if (obj == NULL)
		{
			printf("function %s error param!\n", func->getName());
			return NULL;
		}
		if (obj->getType() == STRING)
		{
			String * str = (String*)obj;
			system(str->getValue());
		}

		return NULL;
	}

	// doFile 函数
	Object * langX_do_file(X3rdFunction *func, const X3rdArgs & args) {
		if (args.index <= 0)
		{
			printf("function %s need at least 1 param!\n", func->getName());
			return NULL;
		}

		Object *obj = args.args[0];
		if (obj == NULL)
		{
			printf("function %s error param!\n", func->getName());
			return NULL;
		}
		if (obj->getType() == STRING)
		{
			String * str = (String*)obj;
			getState()->doFile(str->getValue());
		}

		return NULL;
	}

	// 读取出一个字符串
	Object * langX_scan_string(X3rdFunction *func, const X3rdArgs & args) {
		char t[100] = { 0 };
		scanf("%s", t);

		return new String(t);
	}

	// 读取一行
	Object * langX_read_line(X3rdFunction *func, const X3rdArgs & args) {
		char inputBuffer[2048] = { 0 };
		int inputIndex = 0;

		initTermios(0);
		char c;
		while ((c = getchar()) != '\n') {
			if (c == '\b' && inputIndex > 0) {
				inputBuffer[--inputIndex] = '\0';
				printf("\b \b");
			}
			else {
				inputBuffer[inputIndex++] = c;
				printf("%c", c);
			}
		}
		resetTermios();
		printf("\n");

		return new String(inputBuffer);
	}

	// 读取一个数字
	Object * langX_scan_number(X3rdFunction *func, const X3rdArgs & args) {
		double a;
		scanf("%lf", &a);

		return new Number(a);
	}

	Object * langX_print_stack_trace(X3rdFunction *func, const X3rdArgs & args) {
		func->getLangX()->curThread()->printStackTrace();

		return nullptr;
	}

	Object * langX_exit(X3rdFunction *func, const X3rdArgs & args) {
		int status = 0;

		if (args.index > 0)
		{
			Object *a = args.args[0];
			if (a && a->getType() == NUMBER)
			{
				status = ((Number*)a)->getIntValue();
			}
		}

		exit(status);

		return NULL;
	}

	Object * langX_sy_exists(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING) {
			String *str = (String*)a;
			const char * path = str->getValue();
			if (access(path, F_OK) == 0) {
				return new Number(1);   // 文件存在
			}
			else {
				return new Number(0);
			}
		}

		return NULL;
	}

	// 创建文件夹
	Object * langX_sy_mkdir(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING) {
			String *str = (String*)a;
			const char * path = str->getValue();
			if (mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0) {
				return new Number(1);   // 创建文件夹成功
			}
			else {
				return new Number(0);
			}
		}

		return NULL;
	}

	// 把字符串转换成数字  | 如果遇到不能转换的字符串， 则返回0
	Object * langX_sy_to_int(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING) {
			String *str = (String*)a;
			const char * number = str->getValue();
			int ret = atoi(number);
			return new Number(ret);
		}

		return NULL;
	}

	// 获取当前的工作目录
	Object * langX_sy_cwd(X3rdFunction *func, const X3rdArgs & args) {
		char buf[2048] = { 0 };
		getcwd(buf, sizeof(buf));
		return new String(buf);
	}

	Object * langX_sy_chdir(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING) {
			String *str = (String*)a;
			const char * path = str->getValue();
			int ret = chdir(path);
			return new Number(ret);
		}

		return NULL;
	}

	// 执行一个命令， 并打印输出
	// null 标识参数错误，  -1 标识打开管道失败  1 标识执行成功
	Object * langX_sy_run_and_print(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING) {
			String *str = (String*)a;
			const char * cmd = str->getValue();

			FILE *fp = popen(cmd, "r");
			if (fp == NULL) {
				return new Number(-1);
			}

			char buf[1024] = { 0 };
			while (fgets(buf, 1024, fp) != NULL) {
				printf("%s", buf);
			}
			pclose(fp);
			return new Number(1);
		}

		return NULL;
	}

	// 获取一个对象的元信息
	// 部分属性暂时无法获取到正确的值， 所以不进行赋值操作
	Object * langX_sy_metadata(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		langXObject *obj = c_metadata->newObject();
		if (a) {
			char tmp[1024] = { 0 };
			sprintf(tmp, "%p", a);
			String str(tmp);
			// obj->setMember("memoryAddress", &str);
			String nameStr(a->getName());
			obj->setMember("variableName", &nameStr);
			String charaStr(a->characteristic());
			obj->setMember("characteristic", &charaStr);
			Environment *env = a->getEmergeEnv();
			if (env)
			{
				sprintf(tmp, "%p", env);
				String envStr(tmp);
				//obj->setMember("emergeEnv", &envStr);
			}

			obj->setMember("value", a);
		}

		return obj->addRef();
	}

	// 获取一个元素的类型， 返回一个字符串
	// 可以传来两个参数， 第一个为要鉴定的对象
	// 如果第一个参数是一个 Object类型，即对象类型，如果第二个参数为true 则返回对象的类名， 否则返回 "Object"
	Object * langX_co_typeof(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		const char *typeName = "Null";
		if (a) {
			ObjectType ot = a->getType();
			if (ot == ObjectType::NUMBER)
			{
				typeName = "Number";
			}
			else if (ot == ObjectType::STRING) {
				typeName = "String";
			}
			else if (ot == ObjectType::FUNCTION) {
				typeName = "Function";
			}
			else if (ot == ObjectType::XARRAY) {
				typeName = "Array";
			}
			else if (ot == ObjectType::UNKNOWN)
			{
				typeName = "Unknown";
			}
			else if (ot == ObjectType::OBJECT) {
				Object *b = args.args[1];
				if (b && b->isTrue())
				{
					// 返回类名
					typeName = ((langXObjectRef*)a)->getClassInfo()->getName();
				}
				else {
					typeName = "Object";
				}
			}
		}

		return Allocator::allocateString(typeName);
	}

	// 获取一个对象的类名， 如果该元素不是一个对象，则返回 NullObject
	Object * langX_co_classname(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::OBJECT)
		{
			langXObjectRef *ref = (langXObjectRef*)a;
			const char * name = ref->getClassInfo()->getName();
			return Allocator::allocateString(name);
		}

		return Allocator::allocate(ObjectType::NULLOBJECT);
	}

	Object * langX_sy_isLoadMod(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			String *str = (String*)a;
			bool flag = func->getLangX()->isLoadModule(str->getValue());
			int ret = flag ? 1 : 0;
			return Allocator::allocateNumber(ret);
		}

		return Allocator::allocateNumber(0);
	}

	Object * langX_str_trim(X3rdFunction *func, const X3rdArgs & args) {
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			String *str = (String*)a;
			str->trim();
			return Allocator::allocateString(str->getValue());
		}

		return Allocator::allocateNull();
	}

	Object * langX_get_start_arg(X3rdFunction *func, const X3rdArgs & args) {
		langXState *state = func->getLangX();
		int argc = state->getArgc();
		if (argc <= 0)
		{
			return nullptr;
		}


		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::NUMBER)
		{
			int index = ((Number*)a)->getIntValue();
			if (index >= argc)
			{
				return nullptr;
			}

			char *abc = state->getArgv()[index];
			return Allocator::allocateString(abc);
		}

		return Allocator::allocateNull();
	}

	Object * langX_get_start_arg_size(X3rdFunction *func, const X3rdArgs & args) {
		langXState *state = func->getLangX();
		int argc = state->getArgc();
		return Allocator::allocateNumber(argc);
	}

	Object * langX_get_start_args(X3rdFunction *func, const X3rdArgs & args) {
		langXState *state = func->getLangX();
		int argc = state->getArgc();
		if (argc <= 0)
		{
			return nullptr;
		}

		XArray *arr= Allocator::allocateArray(argc);
		
		char **argv = state->getArgv();
		for (size_t i = 0; i < argc; i++)
		{
			String *str = Allocator::allocateString(argv[i]);
			arr->set(i, str);
		}

		return arr->addRef();
	}

	/**
	 * langX 函数 include(file)  的实现
	 * @param func
	 * @param args
	 * @return
	 */
    Object * langX_include(X3rdFunction *func, const X3rdArgs & args){
        if (args.index <= 0) {
            return nullptr;
        }

        for (int i = 0; i < args.index; ++i) {
            auto tmp = args.args[i];
            if (tmp && tmp->getType() == STRING) {
                // 只 执行字符串格式的内容
                includeFile(((String*)tmp)->getValue());
            }
        }

        return nullptr;
	}

	/**
	 * langX 函数 require(file)  的实现
	 * @param func
	 * @param args
	 * @return
	 */
    Object * langX_require(X3rdFunction *func, const X3rdArgs & args){
        if (args.index <= 0) {
            return nullptr;
        }

        for (int i = 0; i < args.index; ++i) {
            auto tmp = args.args[i];
            if (tmp && tmp->getType() == STRING) {
                // 只 执行字符串格式的内容
                requireFile(((String*)tmp)->getValue());
            }
        }

        return nullptr;
    }

    /**
     * langX 函数 requireOnce(file)  的实现
     * @param func
     * @param args
     * @return
     */
    Object * langX_requireOnce(X3rdFunction *func, const X3rdArgs & args){
        if (args.index <= 0) {
            return nullptr;
        }

        for (int i = 0; i < args.index; ++i) {
            auto tmp = args.args[i];
            if (tmp && tmp->getType() == STRING) {
                // 只 执行字符串格式的内容
                requireOnceFile(((String*)tmp)->getValue());
            }
        }

        return nullptr;
    }

    /**
     * 执行一段字符串
     * @param func
     * @param args
     * @return
     */
    Object * langX_doString(X3rdFunction *func, const X3rdArgs & args){
        if (args.index <= 0) {
            return nullptr;
        }

        auto a = args.args[0];
        if (a && a->getType() == STRING) {
            auto text = ((String*)a)->getValue();

            func->getLangX()->doString(text);
        }

        return nullptr;
    }

	void regFunctions(langXState *state)
	{
		regClasses(state);

		state->reg3rd("print", langX_print);
		state->reg3rd("scanString", langX_scan_string);
		state->reg3rd("scanNumber", langX_scan_number);
		state->reg3rd("printStackTrace", langX_print_stack_trace);
		state->reg3rd("sy_run", langX_system_run);
		state->reg3rd("println", langX_println);
		state->reg3rd("sy_do_file", langX_do_file);
		state->reg3rd("sy_doString", langX_doString);
		state->reg3rd("sy_exit", langX_exit);
		state->reg3rd("readLine", langX_read_line);
		state->reg3rd("sy_exists", langX_sy_exists);
		state->reg3rd("sy_mkdir", langX_sy_mkdir);
		state->reg3rd("sy_to_int", langX_sy_to_int);
		state->reg3rd("sy_cwd", langX_sy_cwd);
		state->reg3rd("sy_chdir", langX_sy_chdir);
		state->reg3rd("sy_cd", langX_sy_chdir);
		state->reg3rd("sy_run_and_print", langX_sy_run_and_print);
		state->reg3rd("sy_metadata", langX_sy_metadata);
		state->reg3rd("co_typeof", langX_co_typeof);
		state->reg3rd("co_classname", langX_co_classname);
		state->reg3rd("sy_isLoadMod", langX_sy_isLoadMod);
		state->reg3rd("sy_arg", langX_get_start_arg);
		state->reg3rd("sy_argc", langX_get_start_arg_size);
		state->reg3rd("sy_argv", langX_get_start_args);

		// 文件相关的函数
		state->reg3rd("include", langX_include);
		state->reg3rd("require", langX_require);
		state->reg3rd("requireOnce", langX_requireOnce);


		// 字符串相关的函数
		state->reg3rd("str_trim", langX_str_trim);
	}


}