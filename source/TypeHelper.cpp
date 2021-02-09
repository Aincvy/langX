//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/9.
//

#include <sstream>
#include <memory.h>

#include "TypeHelper.h"
#include "Number.h"
#include "XArray.h"
#include "StringType.h"
#include "langXObject.h"
#include "NodeCreator.h"
#include "Allocator.h"
#include "Utils.h"
#include "NullObject.h"

namespace langX {

    Number* shortcutNumberZero = new Number(0);
    Number* shortcutNumberOne = new Number(1);
    NullObject* shortcutNullObject = new NullObject();
    String* shortcutEmptyString = new String("");


    void readNumber(const X3rdArgs &args, int index, int *value) {
        if (args.index <= index) {
            return;
        }

        auto tmp = args.args[index];
        if (tmp && tmp->getType() == NUMBER) {
            *value = ((Number *) tmp)->getIntValue();
        }
    }


    bool isNull(Object *obj) {
        return obj == nullptr || obj->getType() == NULLOBJECT;
    }


    void x3rdArgsToArray(const X3rdArgs &args, XArray *arrayObjRef) {
        XArray *arrayRef = arrayObjRef;

        int length = args.index;
        for (size_t i = 0; i < length; i++) {
            arrayRef->set(i, args.args[i]);
        }
    }


    const char *getStringFromObject(langXObject *object, const char *memberName) {
        if (!object) {
            return nullptr;
        }
        auto member = object->getMember(memberName);
        if (member->getType() == NULLOBJECT) {
            return nullptr;
        }

        if (member->getType() == STRING) {
            return ((String *) member)->getValue();
        } else {
            // maybe need throw exception ?
        }

        return nullptr;
    }

    int getIntFromObject(langXObject *object, const char *memberName) {
        auto ptr = OBJECT_NUMBER_MEMBER_PTR(object, memberName);
        if (!ptr) {
            return 0;
        }

        return ptr->getIntValue();
    }

    int getIntFromObject(langXObjectRef *object, const char *memberName) {
        return getIntFromObject(object->getRefObject(), memberName);
    }

    double getDoubleFromObject(langXObject *object, const char *memberName) {
        auto ptr = OBJECT_NUMBER_MEMBER_PTR(object, memberName);
        if (!ptr) {
            return 0;
        }

        return ptr->getDoubleValue();
    }

    double getDoubleFromObject(langXObjectRef *object, const char *memberName) {
        return getDoubleFromObject(object->getRefObject(), memberName);
    }

    Function *create3rdFunc(const char *name, X3rdFuncWorker worker) {
        auto func = new X3rdFunction();
        func->setName(name);
        func->setWorker(worker);
        func->setParamsList(nullptr);
        func->setLangX(getState());

        return func;
    }

    void objToString(Object * obj, char *p, int offset, int maxSize)
    {
        std::stringstream ss;
        auto ref = (langXObjectRef*)obj;
        auto thread = getState()->curThread();
        Function *func = ref->getFunction("toString");
        if (func == nullptr)
        {
            ss << "|[" << obj->characteristic();
        }
        else {

            X3rdArgs args;
            args.object = ref->getRefObject();
            Object *retObj = callFunction(thread, func, &args, ref->getRefObject(), "<call toString() from cpp>");
            if (retObj != nullptr && retObj->getType() == STRING)
            {
                ss << ((String*)retObj)->getValue();
            }
            Allocator::free(retObj);
            retObj = nullptr;
        }

        std::string str = ss.str();
        int size = min(maxSize, (int) str.size());

        memcpy(p + offset, str.c_str(), size);
    }

    void copyX3rdArgs(const X3rdArgs &src, X3rdArgs &dst) {
        dst.object = src.object;
        dst.index = src.index;

        for (int i = 0; i < dst.index; ++i) {
            dst.args[i] = src.args[i];
        }
    }

}