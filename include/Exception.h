#pragma once

namespace langX {

	class langXObject;

	/*
	注册异常类的信息 到 LangX 内

	*/


	// 注册 异常类 到LangX 内
	void regExceptions();

	langXObject *newException(const char * message) ;
	//  className:  异常类的类名
	//  message:  消息内容
	langXObject *newException(const char *className, const char *message);

	// 
	langXObject *newArithmeticException(const char *message);
	langXObject *newNullPointerRefException(const char * message);
	langXObject *newIOException(const char *message);
	langXObject *newNoClassMemberException(const char *message);
	langXObject *newNoClassFunctionException(const char *message);
	langXObject *newClassNotFoundException(const char *message);
	langXObject *newUnsupportedOperationException(const char *message);
	langXObject *newTypeErrorException(const char *message);
	langXObject *newFunctionNotFoundException(const char *message);
	langXObject *newIndexOutOfBoundsException(const char *message);
	langXObject *newRedeclarationException(const char *message);
}