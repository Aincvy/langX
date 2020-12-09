//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/9.
//

#include "TypeHelper.h"
#include "Number.h"

namespace langX{


    void readNumber(const X3rdArgs &args, int index, int *value){
        if (args.index <= index) {
            return;
        }

        auto tmp = args.args[index];
        if (tmp && tmp->getType() == NUMBER) {
            *value = ((Number*)tmp)->getIntValue();
        }
    }


}