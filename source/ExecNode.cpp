#include <stdio.h>
#include "../include/ExecNode.h"
#include "../include/YLlangX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/String.h"
#include "../extern/y.tab.h"
#include "../include/Allocator.h"

namespace langX {
	// �ڴ�� ������
	Allocator m_exec_alloc;

	/*
	  ���ڵ��ֵ���µ���ǰ������
	*/
	void setValueToEnv(const char*name, Object *val) {
		if (val == NULL || name == NULL)
		{
			printf("setValueToEnv Node Args Error. \n");
			return;
		}

		Environment * env = getState()->getCurrentEnv();
		Object *obj = env->getObject(name);
		if (obj == NULL)
		{
			env->putObject(name, val->clone());
		}
		else {
			obj->update(val);
		}
	}

	/*
	  ִ������ڵ�������ӽڵ�
	*/
	void doSubNodes(Node *n) {
		if (n == NULL)
		{
			return;
		}

		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			__execNode(n->opr_obj->op[i]);
		}
	}

	/*
	  �ͷŵ�ǰ�ڵ���ӽڵ��ֵ �ڴ�
	*/
	void freeSubNodes(Node *n) {
		if (n == NULL)
		{
			return;
		}

		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			m_exec_alloc.free(n->opr_obj->op[i]->value);
			n->opr_obj->op[i]->value = NULL;
		}
	}

	/* ���������������ڣ� ��new һ������ȥ
	   ���һ�ŵ���ǰ�Ļ�������
	   �����������֮�� ��ǿ�Ƹ�д left->value ��ֵ 
		
	   0730 ��ֵ����ֵ��ֵΪ ���� Environment �����ֵ�Ŀ�¡
	*/
	void checkVarValue(Node *left, ObjectType rightType) {
		if (left == NULL)
		{
			return;
		}
		// ���Ǳ��� �� �����κδ���
		if (left->type != NODE_VARIABLE)
		{
			return;
		}

		Object *obj = getState()->getObject(left->var_obj->name);
		if (obj == NULL || obj->getType() != rightType)
		{
			obj = m_exec_alloc.allocate(rightType);
			getState()->putObject(left->var_obj->name, obj);
		}
		left->value = obj->clone();
	}

	/* ���һ�½ڵ��Ƿ���� ֵ�� ��������ڣ� �������� */
	void checkValue(Node * node) {
		if (node == NULL)
		{
			return;
		}

		if (node->value == NULL)
		{
			__execNode(node);
		}
	}

	int __readRealNumber(Object *obj, double* v) {
		if (obj == NULL)
		{
			return -1;
		}

		//printf("__readRealNumber1\n");
		if (obj->getType() != NUMBER)
		{
			return -1;
		}
		//printf("__readRealNumber2\n");

		Number * a = (Number*)obj;
		*v = a->getDoubleValue();
		//printf("__readRealNumber: %.2f\n" , (*v));
		return 0;
	}

	bool __tryConvertToBool(Node *n) {
		if (n == NULL)
		{
			return false;
		}

		checkValue(n);
		if (n->value == NULL)
		{
			return false;
		}

		return n->value->isTrue();
	}

	int __getNumberValue(Node*n, double *v) {
		//printf("__getNumberValue00   \n");
		if (n == NULL || v == NULL)
		{
			return -1;
		}

		checkValue(n);
		return __readRealNumber(n->value, v);
	}

	// +  
	// ��������� �Ὣ����洢�ڵ�ǰ�ڵ��� 
	void __exec43(Node *n) {
		//printf("__exec43 n addr: %p\n", n);
		//printf("op_count: %d\n" , n->opr_obj->op_count);
		//__execNode(n->opr_obj->op[0]);
		//__execNode(n->opr_obj->op[1]);
		doSubNodes(n);

		// �ӽڵ��ֵ��Ϊ�˼��㵱ǰ����ֵ�� �����ǰ����ֵ ���� ������ ���ͷŵ��ӽڵ�ֵ���ڴ�
		// �ӽڵ��ֵ�����һ�������� ���ֵ��һ�� new ���ڴ棬 �����һ�������� ���ֵ��һ�� clone ���ֵĶ���

		//n->value = new Number(a + b);
		n->value = m_exec_alloc.allocateNumber(((Number*)n->opr_obj->op[0]->value)->getDoubleValue() + ((Number*)n->opr_obj->op[1]->value)->getDoubleValue());

		//m_exec_alloc.free(n->opr_obj->op[0]->value);
		//m_exec_alloc.free(n->opr_obj->op[1]->value);
		//n->opr_obj->op[0]->value = n->opr_obj->op[1]->value = NULL;
		freeSubNodes(n);

		printf("%.2f\n", ((Number*)n->value)->getDoubleValue() );
	}

	// -
	void __exec45(Node *n) {
		doSubNodes(n);
		//n->value = new Number(a - b);
		n->value = m_exec_alloc.allocateNumber(((Number*)n->opr_obj->op[0]->value)->getDoubleValue() - ((Number*)n->opr_obj->op[1]->value)->getDoubleValue());
		freeSubNodes(n);

		printf("%.2f\n", ((Number*)n->value)->getDoubleValue());
	}

	// *
	void __exec42(Node *n) {
		doSubNodes(n);
		n->value = m_exec_alloc.allocateNumber(((Number*)n->opr_obj->op[0]->value)->getDoubleValue() * ((Number*)n->opr_obj->op[1]->value)->getDoubleValue());
		freeSubNodes(n);

		printf("%.2f\n", ((Number*)n->value)->getDoubleValue());
	}

	// /
	void __exec47(Node *n) {
		doSubNodes(n);
		n->value = m_exec_alloc.allocateNumber(((Number*)n->opr_obj->op[0]->value)->getDoubleValue() / ((Number*)n->opr_obj->op[1]->value)->getDoubleValue());
		freeSubNodes(n);

		printf("%.2f\n", ((Number*)n->value)->getDoubleValue());
	}

	// ��ֵ���� = 
	void __exec61(Node *n) {
		//printf("__exec61 start\n");
		Node *left = n->opr_obj->op[0];
		if (left->type != NODE_VARIABLE)
		{
			printf("left not the NODE_VARIABLE\n");
			return;
		}

		printf("__exec61 left name: %s\n", left->var_obj->name);
		Node *right = n->opr_obj->op[1];
		printf("right->value: %p\n", right->value);
		checkValue(right);
		// ��ֵ�����Ľ�� Ϊ ��ֵ�Ľ��
		if (right->value == NULL)
		{
			n->value = NULL;
		}
		else {
			checkVarValue(left, right->value->getType());
			left->value->update(right->value);

			// �ͷ���ֵ���ڴ� 
			m_exec_alloc.free(right->value);
			right->value = NULL;

			n->value = m_exec_alloc.copy(left->value);
			// ��ֵ��ָ�� Environment �ڵ��ڴ�ĸ��ƣ� ��Ҫ�ͷ�
			m_exec_alloc.free(left->value);
			left->value = NULL;

			// ����ֵ�� Environment 
			setValueToEnv(left->var_obj->name,n->value);
		}

		//assignment(left->var_obj->name, n->value);
	}

	void __execADD_EQ(Node *n) {
		doSubNodes(n);
		Node *left = n->opr_obj->op[0];
		n->value = m_exec_alloc.allocateNumber(((Number*)left->value)->getDoubleValue() + ((Number*)n->opr_obj->op[1]->value)->getDoubleValue());

		setValueToEnv(left->var_obj->name, n->value);

		freeSubNodes(n);
	}

	void __execSUB_EQ(Node *n) {
		doSubNodes(n);
		Node *left = n->opr_obj->op[0];
		n->value = m_exec_alloc.allocateNumber(((Number*)left->value)->getDoubleValue() - ((Number*)n->opr_obj->op[1]->value)->getDoubleValue());

		setValueToEnv(left->var_obj->name, n->value);

		freeSubNodes(n);
	}

	void __execMUL_EQ(Node *n) {
		doSubNodes(n);
		Node *left = n->opr_obj->op[0];
		n->value = m_exec_alloc.allocateNumber(((Number*)left->value)->getDoubleValue() * ((Number*)n->opr_obj->op[1]->value)->getDoubleValue());

		setValueToEnv(left->var_obj->name, n->value);

		freeSubNodes(n);
	}

	void __execDIV_EQ(Node *n) {
		doSubNodes(n);
		Node *left = n->opr_obj->op[0];
		n->value = m_exec_alloc.allocateNumber(((Number*)left->value)->getDoubleValue() / ((Number*)n->opr_obj->op[1]->value)->getDoubleValue());

		setValueToEnv(left->var_obj->name, n->value);

		freeSubNodes(n);
	}


	// �ֺ� ;
	void __exec59(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (n->opr_obj == NULL || n->opr_obj->op_count == 0)
		{
			return;
		}

		for (size_t i = 0; i < n->opr_obj->op_count; i++)
		{
			__execNode(n->opr_obj->op[i]);
		}
	}

	// ���ű��ʽ
	void __exec44(Node *n) {
		// ������ �ֺű��ʽ���Ӧ�ã� ����Ӧ�þ�OK�ˡ� 
		__exec59(n);
	}

	// ���ţ� >
	void __exec62(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a > b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}

	}

	// ���ڵ���
	void __execGE_OP(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a >= b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}

	}

	// ���ţ� <
	void __exec60(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a < b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	// С�ڵ���
	void __execLE_OP(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a <= b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	// ����
	void __execEQ_OP(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a == b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	// ������
	void __execNE_OP(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a != b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	void __execOPAND(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			n->opr_obj->bool_value = __tryConvertToBool(n->opr_obj->op[1]);
			//__execNode(n->opr_obj->op[1]);
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	void __execOPOR(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = __tryConvertToBool(n->opr_obj->op[1]);
		}
	}

	void __execIF(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			__execNode(n->opr_obj->op[1]);
		}
		else {
			if (n->opr_obj->op_count >= 3)
			{
				__execNode(n->opr_obj->op[2]);
			}
		}
	}

	void __execWHILE(Node *n) {
		if (n == NULL || n->opr_obj == NULL || n->opr_obj->op_count != 2)
		{
			return;
		}

		while (__tryConvertToBool(n->opr_obj->op[0]))
		{
			__execNode(n->opr_obj->op[1]);
		}
	}

	void __execFOR(Node *n) {
		if (n == NULL || n->opr_obj == NULL || n->opr_obj->op_count != 4)
		{
			return;
		}

		for (__execNode(n->opr_obj->op[0]); __tryConvertToBool(n->opr_obj->op[1]); __execNode(n->opr_obj->op[2]))
		{
			__execNode(n->opr_obj->op[3]);
		}
	}

	/*
	 * ִ�нڵ㣬  �ڵ�Ľ�� �� ����  Node.value ��
	 * ����һ�� Object ���͵�ָ��    07-24
	 */
	void __execNode(Node *node) {
		if (node == NULL)
		{
			return;
		}
		// ����ڵ����ֵ�� ��˵������ڵ��Ѿ��������
		// �����½��м���͸�ֵ
		//if (node->value != NULL)
		//{
		//	return;
		//}

		//printf("__execNode 01x\n");
		//printf("node addr: %p\n",node);
		if (node->type == NODE_VARIABLE)
		{
			printf("__execNode NODE_VARIABLE\n");
			// Э������ ʹ������ obj ���ڸ�ֵ״̬
			if (node->value == NULL)
			{
				//printf("__execNode 01\n");
				Object *obj = getValue(node->var_obj->name);

				if (obj == NULL)
				{
					printf("var %s=null \n", node->var_obj->name);
					node->value = NULL;
				}
				else {
					if (obj->getType() == NUMBER)
					{
						Number * number = (Number*)obj;
						printf("var %s=%.2f \n", node->var_obj->name, number->getDoubleValue());
					}

					// ��������Ϊ һ�� copy 
					node->value = obj->clone();
				}

			}

			return;
		}
		else if (node->type == NODE_CONSTANT_NUMBER)
		{
			printf("__execNode NODE_CONSTANT_NUMBER\n");
			node->value = m_exec_alloc.allocateNumber(node->con_obj->dValue);
			return;
		}
		else if (node->type == NODE_CONSTANT_STRING)
		{
			printf("__execNode NODE_CONSTANT_STRING\n");
			return;
		}


		printf("exec operator node. opr is: %d\n", node->opr_obj->opr);
		switch (node->opr_obj->opr)
		{
		case '+':
			__exec43(node);
			break;
		case '-':
			__exec45(node);
			break;
		case '*':
			__exec42(node);
			break;
		case '/':
			__exec47(node);
			break;
		case '=':
			__exec61(node);
			break;
		case ';':
			__exec59(node);
			break;
		case '>':
			__exec62(node);
			break;
		case '<':
			__exec60(node);
			break;
		case ADD_EQ:
			__execADD_EQ(node);
			break;
		case SUB_EQ:
			__execSUB_EQ(node);
			break;
		case MUL_EQ:
			__execMUL_EQ(node);
			break;
		case DIV_EQ:
			__execDIV_EQ(node);
			break;
		case LE_OP:
			__execLE_OP(node);
			break;
		case GE_OP:
			__execGE_OP(node);
			break;
		case EQ_OP:
			__execEQ_OP(node);
			break;
		case NE_OP:
			__execNE_OP(node);
			break;
		case AND_OP:
			__execOPAND(node);
			break;
		case OR_OP:
			__execOPOR(node);
		case IF:
			__execIF(node);
			break;
		case WHILE:
			__execWHILE(node);
		case FOR:
			__execFOR(node);
		default:
			break;
		}

	}

}

