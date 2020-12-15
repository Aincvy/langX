//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/9.
//

#include "TypeHelper.h"
#include "Number.h"
#include "XArray.h"
#include "StringType.h"
#include "langXObject.h"

namespace langX {


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


}