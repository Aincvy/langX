#include <string>
#include "../include/Object.h"
#include "../include/Utils.h"
#include "../include/XArray.h"

namespace langX {
	Object::Object()
	{
		this->m_ref_count = 0;

		char t[100];
		randomCharacteristic(t, 100, this, 8);
		this->m_characteristic = std::string(t);
	}

	Object::~Object()
	{
	}
	void Object::incRefCount()
	{
		this->m_ref_count++;
	}
	void Object::decRefCount()
	{
		if (--this->m_ref_count <= 0) {
			this->finalize();
		}
	}
	bool Object::isLocal() const
	{
		return this->m_is_local;
	}
	bool Object::isPrivate() const
	{
		return this->m_is_private;
	}
	bool Object::isPublic() const
	{
		return this->m_is_public;
	}

	bool Object::isConst() const
	{
		return this->m_is_const;
	}

	void Object::setConst(bool flag)
	{
		this->m_is_const = flag;
	}

	void Object::setLocal(bool flag)
	{
		this->m_is_local = flag;
	}

	Environment * Object::getEmergeEnv() const
	{
		return this->m_emerge_env;
	}

	void Object::setEmergeEnv(Environment *env)
	{
		this->m_emerge_env = env;
	}

	const char * Object::getName() const
	{
		return this->m_name.c_str();
	}

	void Object::setName(std::string name)
	{
		this->m_name = name;
	}

	const char * Object::characteristic() const
	{
		return this->m_characteristic.c_str();
	}

	void Object::setCharacteristic(const char *a)
	{
		this->m_characteristic = std::string(a);
	}

	NodeLink * newNodeLink(NodeLink *previous, Node *node) {
		NodeLink *nodeLink = (NodeLink *)calloc(1, sizeof(NodeLink));
		nodeLink->previous = previous;
		nodeLink->node = node;
		nodeLink->index = 0;
		nodeLink->backAfterExec = false;
		nodeLink->flag = false;
		nodeLink->next = NULL;
		if (previous != NULL) {
			previous->next = nodeLink;
		}
		return nodeLink;
	}

	/*
	 * 释放这个节点占用的内存
	 */
	void freeNodeLink(NodeLink *nodeLink) {
		if (nodeLink == NULL) {
			return;
		}

		NodeLink *previous = nodeLink->previous;
		if (previous != NULL) {
			previous->next = NULL;
		}
		nodeLink->previous = NULL;
		if (nodeLink->ptr_u != NULL)
		{
			free(nodeLink->ptr_u);
			nodeLink->ptr_u = NULL;
		}
		nodeLink->tryEnv = NULL;
		free(nodeLink);
	}

	void x3rdArgsToArray(const X3rdArgs& args, XArray* arrayObjRef) {
		XArray *arrayRef = arrayObjRef;

		int length = args.index;
		for (size_t i = 0; i < length; i++)
		{
			arrayRef->set(i, args.args[i]);
		}
	}

}