#pragma once

#include <X3rdModule.h>

#include <Python.h>

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

    /**
     * 释放一个 PyObject* 得引用(计数 ？)
     *
     */
    void freePyObjectRef(PyObject *obj);

	/**
	 * 转换langX 对象成一个 PyObject
	 * 支持 Number, String, Array(=> Tuple), langXObject(only PyObject instance..)
	 *
	 * @return 新的引用， 需要手动释放 ,使用下面得 freePyObjectRef() 函数来释放引用
	 */
	PyObject * langXToPyObject(Object *);


	/**
	 * 尝试矫正 对象得 python 类型
	 * @param obj
	 */
    void detectPyType(XClassPyObject *obj);

	/**
	 * 将 python得 错误信息输出到日志里面
	 */
    void logPythonErrorMsg();

    /**
     * 把一个 langX 对象转换成一个python 对象
     * @param obj
     * @return
     */
    PyObject * langXToPyObject(Object *obj);

	extern PythonModule* pythonModule;
	// python pyModule 得日志
	extern Logger* pythonModuleLogger;

}

int loadModule(langX::X3rdModule *& mod);
