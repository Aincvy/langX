#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#ifdef WIN32
#else
#include <unistd.h>
#include <termios.h>
#include <sys/stat.h>
#endif

#include "../include/RegFunctions.h"
#include "../include/Function.h"
#include "../include/Object.h"
#include "../include/String.h"
#include "../include/Number.h"
#include "../include/YLlangX.h"
#include "../include/langXThread.h"


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

	// 打印语句之后自动换行
	Object * langX_println(X3rdFunction *func, const X3rdArgs & args) {
		if (args.index <= 0)
		{
			printf("function %s need at least 1 param!\n", func->getName());
			return NULL;
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
				str->simpleEscape();

				printf(str->getValue());
			}
			else if (obj->getType() == NUMBER)
			{
				printf("%f", ((Number*)obj)->getDoubleValue());
			}

			else if (obj->getType() == OBJECT)
			{
				char atmp[2048] = { 0 };
				objToString(obj, atmp, 0, 2048);
				printf(atmp);
			}
		}
		printf("\n");

		return NULL;
	}

	// c printf 函数 的桥接
	Object * langX_print(X3rdFunction *func, const X3rdArgs & args) {
		if (args.index <= 0)
		{
			printf("function %s need at least 1 param!\n", func->getName());
			return NULL;
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
				str->simpleEscape();

				printf(str->getValue());
			}
			else if (obj->getType() == NUMBER)
			{
				printf("%f", ((Number*)obj)->getDoubleValue());
			}

			else if (obj->getType() == OBJECT)
			{
				char atmp[2048] = { 0 };
				objToString(obj, atmp, 0, 2048);
				printf(atmp);
			}
		}

		return NULL;
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
			str->simpleEscape();
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
			//str->simpleEscape();
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

		return NULL;
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

	void regFunctions(langXState *state)
	{
		state->reg3rd("print", langX_print);
		state->reg3rd("scanString", langX_scan_string);
		state->reg3rd("scanNumber", langX_scan_number);
		state->reg3rd("printStackTrace", langX_print_stack_trace);
		state->reg3rd("systemRun", langX_system_run);
		state->reg3rd("println", langX_println);
		state->reg3rd("doFile", langX_do_file);
		state->reg3rd("exit", langX_exit);
		state->reg3rd("readLine", langX_read_line);
		state->reg3rd("sy_exists", langX_sy_exists);
		state->reg3rd("sy_mkdir", langX_sy_mkdir);
		state->reg3rd("sy_to_int", langX_sy_to_int);
		state->reg3rd("sy_cwd", langX_sy_cwd);
		state->reg3rd("sy_chdir", langX_sy_chdir);
		state->reg3rd("sy_run_and_print", langX_sy_run_and_print);

	}

}