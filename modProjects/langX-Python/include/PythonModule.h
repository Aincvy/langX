#pragma once

#include "../../../include/X3rdModule.h"

#ifdef WIN32 
#include "../../../lib/Python-3.5.2/Include/Python.h"
#else
#include <python/Python.h>
#endif

namespace langX {

	class langXObject;
	class Object;
	class Logger;

	class PythonModule : public X3rdModule
	{
	public:
		PythonModule();
		~PythonModule();

		int init(langXState *) override;

		virtual int unload(langXState *) override;

		const char * getDescription() const override;

		const char * getAuthor() const override;

		const char * getRepository() const override;

		const char * getVersion() const override;

	private:

	};


	enum PyObjectType
	{
		// 未知的
		Unknown = 0,

		// 模块
		Module =1,

		// python 实例
		PyInstance ,

		// python 类
		PyClass ,

		// python 函数
		PyFunction,

		// 数组  元祖
		Tuple,

		// 字典
		Dict ,

		// 列表
		PyListX , 

		PyNumber,

		PyString,

		PyBool
	};


	// langX 的 PyObject  类型
	typedef struct 
	{
		// python 对象
		PyObject *pyObj;
		// 类型
		PyObjectType type;
		// 大小[数组或者字典的]
		int size;
	} XClassPyObject;

	XClassPyObject * createXClassPyObject();
	void freeXClassPyObject(XClassPyObject **);
	langXObject * createLangXObjectPyObj(PyObject * pyObj, PyObjectType type);
	langXObject * newPyException(const char * message);
	langXObject * createLangXObjectPyObjEasy(PyObject * pyObj, PyObjectType type);

	Object * langX_PyObject_get_impl(XClassPyObject *obj, Object *a);
	Object * langX_PyObject_set_impl(XClassPyObject * obj, Object * key, Object *value);

	PyObject * langXToPyObject(Object *);


	extern PythonModule* pythonModule;
	// python module 得日志
	extern Logger* pythonModuleLogger;

}

int loadModule(langX::X3rdModule *& mod);
