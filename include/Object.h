#pragma once

/*
*   ����ʱ�䣺  2016-07-07
*   ���ߣ� The World(world@aincvy.com)
*
*   �ļ�������
*   ������     ��ʾһ�� langX ���� 
*/

namespace langX {


	// ��������
	enum ObjectType
	{
		UNKNOWN=100, NUMBER , STRING, FUNCTION
	};


	class Object
	{
	public:
		Object();
		~Object();

		/* ��ǰֵ���Ա�ʾΪ��ô��  null,0,false �������ʾΪ��  */
		virtual bool isTrue() const = 0;
		/* ��õ�ǰ���������  */
		virtual ObjectType getType() const = 0;
	private:

	};

	struct Variable
	{
		char * name;
		// ���������ֵ��   ������� ��FreeNode �����в������ͷ�
		Object *obj;
	};

	enum NodeType
	{
		// ���ֳ����ڵ�
		NODE_CONSTANT_NUMBER = 50,
		// �ַ��������ڵ�
		NODE_CONSTANT_STRING,
		// �����ڵ�
		NODE_VARIABLE ,
		// �������ڵ�
		NODE_OPERATOR
	};

	struct Constant
	{
		int iValue;
		double dValue;
		char* sValue;
		char cValue;
	};

	struct Operator
	{
		// ��Ҳ��֪����ɶ
		struct Node** op;
		int op_count;
		// ��������ʲô
		int opr;
		// ��ǰ���������Ľ��, ������� ��FreeNode �����в������ͷ�
		Object *obj;
		// ��ʱ���bool ���
		bool bool_value;
	};

	struct Node
	{
		NodeType type;
		// ��ִ�н���֮���Ƿ���� free ����
		bool freeOnExeced;

		Variable *var_obj;
		Constant *con_obj;
		Operator *opr_obj;
	};

	// �����б� ,��󲻳���30������
	struct ArgsList
	{
		char* args[30];
		// ��������
		int index;
	};
}