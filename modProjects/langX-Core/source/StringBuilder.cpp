#include <sstream>
#include <iostream>
#include <algorithm>

#include "RegDefaultClasses.h"

#include "langXSimple.h"

namespace langX {

	// 追加字符串到 这个里面
	void append(std::stringstream &ss, Object *a, const char* extra) {
		if (!a) {
			ss << "null";
		}
		else {
			if (a->getType() == ObjectType::NUMBER) {
				Number *n = (Number*)a;
				if (n->isInteger()) {
					ss << n->getIntValue();
				}
				else {
					ss << n->getDoubleValue();
				}
			}
			else if (a->getType() == ObjectType::STRING) {
				String *str = (String*)a;
				str->simpleEscape();
				ss << str->getValue();
			}
			else if (a->getType() == NULLOBJECT)
			{
				ss << "null";

			}
			else if (a->getType() == FUNCTION)
			{
				ss << "function@[" << a->characteristic();
			}
			else if (a->getType() == OBJECT)
			{
				char tmp[2048] = { 0 };
				objToString(a, tmp, 0, 2048);
				ss << tmp;
			}
		}

		if (extra) {
			ss << extra;
		}
	}


	Object * langX_StringBuilder_append(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_StringBuilder_append error! NO OBJ!\n");
			return nullptr;
		}

		std::stringstream& ss = *((std::stringstream*) args.object->get3rdObj());
		for (auto i = 0; i < args.index; i++) {
			Object *a = args.args[i];
			append(ss, a, nullptr);
		}

		return nullptr;
	}


	Object * langX_StringBuilder_appendLine(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_StringBuilder_appendLine error! NO OBJ!\n");
			return nullptr;
		}
		
		std::stringstream& ss = *((std::stringstream*) args.object->get3rdObj());
		for (auto i = 0; i < args.index; i++) {
			Object *a = args.args[i];
			append(ss, a, nullptr);
		}

		ss << "\n";

		return nullptr;
	}


	Object * langX_StringBuilder_toString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_StringBuilder_toString error! NO OBJ!\n");
			return nullptr;
		}

		std::stringstream& ss = *((std::stringstream*) args.object->get3rdObj());
		
		return Allocator::allocateString(ss.str().c_str());;
	}


	Object * langX_StringBuilder_length(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_StringBuilder_length error! NO OBJ!\n");
			return nullptr;
		}

		std::stringstream& ss = *((std::stringstream*) args.object->get3rdObj());
		ss.seekg(0, std::ios::end);
		int size = ss.tellg();

		return Allocator::allocateNumber(size);
	}


	Object * langX_StringBuilder_reverse(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_StringBuilder_reverse error! NO OBJ!\n");
			return nullptr;
		}

		std::stringstream& ss = *((std::stringstream*) args.object->get3rdObj());
		std::string string = ss.str();
		std::string ns(string.rbegin(), string.rend());
		ss.str(ns);
		
		printf("ns: %s\n", ns.c_str());
		return nullptr;
	}

	Object * langX_StringBuilder_StringBuilder(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_StringBuilder_StringBuilder_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::stringstream *ss = new std::stringstream();
		args.object->set3rdObj(ss);

		return nullptr;
	}


	Object * langX_StringBuilder_StringBuilder_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_StringBuilder_StringBuilder_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::stringstream *ss = (std::stringstream *)args.object->get3rdObj();
		delete ss;
		args.object->set3rdObj(nullptr);

		return nullptr;
	}


	int regStringBuilder(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("StringBuilder");
		info->addFunction("StringBuilder", create3rdFunc("StringBuilder", langX_StringBuilder_StringBuilder));
		info->addFunction("~StringBuilder", create3rdFunc("~StringBuilder", langX_StringBuilder_StringBuilder_Dtor));
		info->addFunction("append", create3rdFunc("append", langX_StringBuilder_append));
		info->addFunction("appendLine", create3rdFunc("appendLine", langX_StringBuilder_appendLine));
		info->addFunction("toString", create3rdFunc("toString", langX_StringBuilder_toString));
		info->addFunction("length", create3rdFunc("length", langX_StringBuilder_length));
		info->addFunction("reverse", create3rdFunc("reverse", langX_StringBuilder_reverse));

		space->putClass(info);

		return 0;
	}
}


