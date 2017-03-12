#include "../include/Exception.h"
#include "../include/Object.h"
#include "../include/YLlangX.h"
#include "../include/ClassInfo.h"
#include "../include/String.h"
#include "../include/Function.h"
#include "../include/langXObject.h"
#include "../include/langXThread.h"

namespace langX {

	// 构造方法
	Object * langX_Exception_Exception(X3rdFunction *func, const X3rdArgs & args) {
		if (args.object == NULL)
		{
			printf("langX_Exception_Exception error! NO OBJ!\n");
			return NULL;
		}

		langXObject * object = args.object;
		if (args.index <= 0)
		{
			printf("langX_Exception_Exception error! NO ARG!\n");
			return NULL;
		}

		if (args.args[0]->getType() != STRING)
		{
			printf("langX_Exception_Exception error! TYPE ERROR!\n");
			return NULL;
		}

		object->setMember("message", args.args[0]);
		return NULL;
	}

	// 异常类的 get Message 方法
	Object * langX_Exception_getMessage(X3rdFunction *func, const X3rdArgs & args) {
		// 错误判断等会做
		if (args.object == NULL)
		{
			printf("langX_Exception_getMessage error! NO OBJ!\n");
			return NULL;
		}

		return args.object->getMember("message");
	}

	// 打印堆栈信息
	Object * langX_Exception_printStackTrace(X3rdFunction *func, const X3rdArgs & args) {

		// 先打印exception 的message
		if (args.object == NULL)
		{
			printf("langX_Exception_getMessage error! NO OBJ!\n");
			return NULL;
		}

		NodeFileInfo f = getCurrentNodeFileInfo();
		printf("%s: %s  \n%s\n", args.object->getClassName(), ((String*)args.object->getMember("message"))->getValue(), fileInfoString(f).c_str());

		func->getLangX()->curThread()->printStackTrace();

		return NULL;
	}

	void regExceptions()
	{
		langXState* l = getState();

		// Exception
		ClassInfo *exception = new ClassInfo("Exception");
		exception->addMember("message", new String(""));
		exception->addFunction("Exception", create3rdFunc("Exception", langX_Exception_Exception));
		exception->addFunction("getMessage", create3rdFunc("getMessage", langX_Exception_getMessage));
		exception->addFunction("printStackTrace", create3rdFunc("printStackTrace", langX_Exception_printStackTrace));
		l->regClassToGlobal(exception);

		// ArithmeticException    计算异常
		ClassInfo *arithmeticException = new ClassInfo("ArithmeticException");
		arithmeticException->setParent(exception);
		arithmeticException->addFunction("ArithmeticException", create3rdFunc("ArithmeticException", langX_Exception_Exception));
		l->regClassToGlobal(arithmeticException);

		// NullPointerRefException   空指针异常
		ClassInfo *nullPointerRefException = new ClassInfo("NullPointerRefException");
		nullPointerRefException->setParent(exception);
		nullPointerRefException->addFunction("NullPointerRefException", create3rdFunc("NullPointerRefException", langX_Exception_Exception));
		l->regClassToGlobal(nullPointerRefException);

		//  IOException       IO 异常
		ClassInfo *ioException = new ClassInfo("IOException");
		ioException->setParent(exception);
		ioException->addFunction("IOException", create3rdFunc("IOException", langX_Exception_Exception));
		l->regClassToGlobal(ioException);

		//   MemberException   成员异常
		ClassInfo *memberException = new ClassInfo("MemberException");
		memberException->setParent(exception);
		l->regClassToGlobal(memberException);

		//   NoClassMemberException  没有类成员异常
		ClassInfo *noClassMemberException = new ClassInfo("NoClassMemberException");
		noClassMemberException->setParent(memberException);
		l->regClassToGlobal(noClassMemberException);

		//   NoClassFunctionException  没有类函数异常
		ClassInfo *noClassFunctionException = new ClassInfo("NoClassFunctionException");
		noClassFunctionException->setParent(memberException);
		l->regClassToGlobal(noClassFunctionException);

		//   ClassNotFoundException    类没找到异常
		ClassInfo *classNotFoundException = new ClassInfo("ClassNotFoundException");
		classNotFoundException->setParent(memberException);
		l->regClassToGlobal(classNotFoundException);

		// UnsupportedOperationException   不支持的操作异常
		ClassInfo *unsupportedOperationException = new ClassInfo("UnsupportedOperationException");
		unsupportedOperationException->setParent(exception);
		l->regClassToGlobal(unsupportedOperationException);

		// TypeErrorException     类型错误异常
		ClassInfo *typeErrorException = new ClassInfo("TypeErrorException");
		typeErrorException->setParent(exception);
		l->regClassToGlobal(typeErrorException);

		// FunctionNotFoundException    函数未找到异常
		ClassInfo *functionNotFoundException = new ClassInfo("FunctionNotFoundException");
		functionNotFoundException->setParent(exception);
		l->regClassToGlobal(functionNotFoundException);

		// IndexOutOfBoundsException    下标越界异常
		ClassInfo *indexOutOfBoundsException = new ClassInfo("IndexOutOfBoundsException");
		indexOutOfBoundsException->setParent(exception);
		l->regClassToGlobal(indexOutOfBoundsException);

		// RedeclarationException      重复声明异常
		ClassInfo *redeclarationException = new ClassInfo("RedeclarationException");
		redeclarationException->setParent(exception);
		l->regClassToGlobal(redeclarationException);

		// FileNotFoundException      文件未找到异常
		ClassInfo *fileNotFoundException = new ClassInfo("FileNotFoundException");
		fileNotFoundException->setParent(exception);
		l->regClassToGlobal(fileNotFoundException);

		// InnerException      内部异常
		ClassInfo * innerException = new ClassInfo("InnerException");
		innerException->setParent(exception);
		l->regClassToGlobal(innerException);
	}

	langXObject * newException(const char * message)
	{
		return newException("Exception", message);
	}

	langXObject * newException(const char * className, const char * message)
	{
		langXObject *obj = getState()->newObject(className);
		if (obj == NULL)
		{
			printf("class error!\n");
			return NULL;
		}
		obj->setMember("message", new String(message));
		return obj;
	}

	langXObject * newArithmeticException(const char * message)
	{
		return newException("ArithmeticException", message);
	}

	langXObject * newNullPointerRefException(const char * message)
	{
		return newException("NullPointerRefException", message);
	}

	langXObject * newIOException(const char * message)
	{
		return newException("IOException", message);
	}

	langXObject * newNoClassMemberException(const char * message)
	{
		return newException("NoClassMemberException", message);
	}

	langXObject * newNoClassFunctionException(const char * message)
	{
		return newException("NoClassFunctionException", message);
	}

	langXObject * newClassNotFoundException(const char * message)
	{
		return newException("ClassNotFoundException", message);
	}

	langXObject * newUnsupportedOperationException(const char * message)
	{
		return  newException("UnsupportedOperationException", message);
	}

	langXObject * newTypeErrorException(const char * message)
	{
		return  newException("TypeErrorException", message);
	}

	langXObject * newFunctionNotFoundException(const char * message)
	{
		return  newException("FunctionNotFoundException", message);
	}

	langXObject * newIndexOutOfBoundsException(const char * message)
	{
		return  newException("IndexOutOfBoundsException", message);
	}

	langXObject * newRedeclarationException(const char * message)
	{
		return  newException("RedeclarationException", message);
	}

	langXObject * newFileNotFoundException(const char * message)
	{
		return  newException("FileNotFoundException", message);
	}

	langXObject * newInnerException(const char * message)
	{
		return  newException("InnerException", message);
	}

}