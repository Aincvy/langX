#include <string>

#include "../include/RegCoreModule.h"
#include "../include/CoreFileStream.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/String.h"

namespace langX {

	static ClassInfo *fileStreamClass;

	Object * langX_FileStream_close(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_close error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();

		if (!cfs->cppFStream.is_open())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		cfs->cppFStream.close();

		return nullptr;
	}



	Object * langX_FileStream_eof(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_eof error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();
		if (cfs->cppFStream.eof())
		{
			return Allocator::allocateNumber(1);
		}

		return Allocator::allocateNumber(0);
	}



	Object * langX_FileStream_length(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_length error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();

		if (!cfs->cppFStream.is_open())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		std::fstream & fs = cfs->cppFStream;
		long a = fs.tellg();
		fs.seekg(std::ios::end);
		long size = fs.tellg();
		fs.seekg(a, std::ios::beg);

		return Allocator::allocateNumber(size);
	}



	Object * langX_FileStream_writeLine(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_writeLine error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();

		if (!cfs->cppFStream.is_open())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		Object *a = args.args[0];
		if (a && a->getType() == STRING)
		{
			const char * str = ((String*)a)->getValue();
			long l = cfs->cppFStream.tellp();
			cfs->cppFStream << str << std::endl;
			long b = ((long)cfs->cppFStream.tellp()) - l;
			return Allocator::allocateNumber(b);
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_FileStream_writeByte(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_writeByte error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();

		if (!cfs->cppFStream.is_open())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		Object * a = args.args[0];
		if (a && a->getType() == NUMBER)
		{
			// 
		}

		return nullptr;
	}



	Object * langX_FileStream_write(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_write error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();

		if (!cfs->cppFStream.is_open())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		Object * a = args.args[0];
		if (a)
		{
			if (a->getType() == NUMBER)
			{
				Number * num = (Number*)a;
				if (num->isInteger())
				{
					cfs->cppFStream << num->getIntValue();
				}
				else {
					cfs->cppFStream << num->getDoubleValue();
				}
			}
			else if (a->getType() == STRING)
			{
				String * str = (String*)a;
				cfs->cppFStream << str->getValue();
			}
		}

		return nullptr;
	}



	Object * langX_FileStream_readLine(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_readLine error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();
		
		if (!cfs->cppFStream.is_open())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		std::string str;
		
		if (std::getline(cfs->cppFStream, str))
		{
			return Allocator::allocateString(str.c_str());
		}


		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_FileStream_read(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_read error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();

		if (!cfs->cppFStream.is_open())
		{
			return Allocator::allocate(NULLOBJECT);
		}




		return nullptr;
	}



	Object * langX_FileStream_FileStream_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_FileStream_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = (CoreFileStream *)args.object->get3rdObj();
		freeCoreFileStream(cfs);

		return nullptr;
	}



	Object * langX_FileStream_FileStream(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_FileStream_FileStream error! NO OBJ!\n");
			return nullptr;
		}

		CoreFileStream * cfs = createCoreFileStream();
		args.object->set3rdObj(cfs);

		return nullptr;
	}



	int regFileStream(langXState *state, XNameSpace* space , ClassInfo *stream) {

		ClassInfo *info = new ClassInfo("FileStream");
		info->setParent(stream);
		info->addFunction("close", create3rdFunc("close", langX_FileStream_close));
		info->addFunction("eof", create3rdFunc("eof", langX_FileStream_eof));
		info->addFunction("length", create3rdFunc("length", langX_FileStream_length));
		info->addFunction("writeLine", create3rdFunc("writeLine", langX_FileStream_writeLine));
		info->addFunction("writeByte", create3rdFunc("writeByte", langX_FileStream_writeByte));
		info->addFunction("write", create3rdFunc("write", langX_FileStream_write));
		info->addFunction("readLine", create3rdFunc("readLine", langX_FileStream_readLine));
		info->addFunction("read", create3rdFunc("read", langX_FileStream_read));
		info->addFunction("~FileStream", create3rdFunc("~FileStream", langX_FileStream_FileStream_Dtor));
		info->addFunction("FileStream", create3rdFunc("FileStream", langX_FileStream_FileStream));

		fileStreamClass = info;
		space->putClass(info);

		return 0;
	}

	void freeCoreFileStream(CoreFileStream *cfs) {
		if (!cfs)
		{
			return;
		}

		if (cfs->cppFStream.is_open())
		{
			cfs->cppFStream.flush();
			cfs->cppFStream.close();
		}

		free(cfs);
	}

	CoreFileStream* createCoreFileStream(const char *path)
	{

		CoreFileStream* ptr = (CoreFileStream*) calloc(1, sizeof(CoreFileStream));
		ptr->cppFStream.open(path, std::ios::in | std::ios::out); 

		return ptr;
	}

	CoreFileStream * createCoreFileStream()
	{
		CoreFileStream* ptr = (CoreFileStream*)calloc(1, sizeof(CoreFileStream));

		return ptr;
	}

	langXObject* createFileStreamObj(const char *path)
	{
		langXObject* obj = fileStreamClass->newObject();

		obj->set3rdObj(createCoreFileStream(path));

		return obj;
	}

	langXObject* createFileStreamObj(CoreFileStream * cfs) {
		langXObject* obj = fileStreamClass->newObject();

		obj->set3rdObj(cfs);

		return obj;
	}

}


