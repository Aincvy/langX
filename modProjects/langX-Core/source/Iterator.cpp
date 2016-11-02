#include <iterator>
#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"

namespace langX {

	Object * langX_Iterator_Iterator(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}

	Object * langX_Iterator_hasNext(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}

	Object * langX_Iterator_next(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}


	// ×¢²á Iterator Ààs
	int regIterator(langXState *state, XNameSpace * space) {

		ClassInfo *iterator = new ClassInfo("Iterator");
		iterator->addFunction("Iterator", create3rdFunc("hasNext", langX_Iterator_Iterator));
		iterator->addFunction("hasNext" , create3rdFunc("hasNext", langX_Iterator_hasNext));
		iterator->addFunction("next", create3rdFunc("next", langX_Iterator_next));
		space->putClass(iterator);

		return 0;
	}

}