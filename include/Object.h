#pragma once

/*
*   ����ʱ�䣺  2016-07-07
*   ���ߣ� The World(world@aincvy.com)
*
*   �ļ�������
*   ������     ��ʾһ�� langX ���� 
*/

namespace langX {

//  �����ĸ���
#define PARAM_COUNT 30


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

		/* ������ǰ��������ô��� */
		void incRefCount();
		/* �Լ���ǰ��������ô����� �����ǰ��������ô���С�ڵ���0  �� �����ٵ�ǰ����   */
		void decRefCount();

		// ��ǰ�����Ƿ���һ�� local ����
		bool isLocal() const;
		// ��ǰ�����Ƿ���һ�� private ����
		bool isPrivate() const;
		// ��ǰ�����Ƿ���һ�� public ����
		bool isPublic() const;

		/* ��ǰֵ���Ա�ʾΪ��ô��  null,0,false �������ʾΪ��  */
		virtual bool isTrue() const = 0;
		/* ��õ�ǰ���������  */
		virtual ObjectType getType() const = 0;
		/* ��¡��ǰ���� ���س�һ���µĶ��� */
		virtual Object* clone() const = 0;

		/* ���Լ�Update ��Ŀ���ֵ */
		virtual void update(Object *) = 0;

	private:
		int m_ref_count;

		/* ����������java ����������� ������˼�Ƕ�����
		�ڵ�ǰ�ﾳ�£� �������Ӧ����ɵĹ���Ϊ�� �ɵ��Լ�   */
		virtual void finalize() = 0;

		bool m_is_local = false;
		bool m_is_private = false;
		bool m_is_public = false;
	};

	struct Variable
	{
		char * name;
		
		// 07-23 ע��  ͳһ���ڵ������������ Node.value ��
		// ���������ֵ��   ������� ��FreeNode �����в������ͷ�
		//Object *obj;
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
		NODE_OPERATOR ,
		// ʵ�νڵ�   
		NODE_ARGS 
	};

	// �ڵ��״̬�� ���磺 ��������ѭ���ڣ��ں�����
	struct NodeState
	{
		// ��ѭ���ڵ����
		bool in_loop;
		// �ں����ڵ����
		bool in_func;
		// ��switch �����
		bool in_switch;

		// �Ƿ��� break ״̬
		bool isBreak;
		// �Ƿ��� return ״̬
		bool isReturn;
		// ��case ��ʱ���Ƿ���Ҫ����case ������
		bool isCaseNeedCon;
		// �Ƿ��Ǻ�׺
		bool isSuffix;
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

		// 07-23 ע�ͣ� ������� Node.value ��
		// ��ǰ���������Ľ��, ������� ��FreeNode �����в������ͷ�
		//Object *obj;
	};

	struct Node
	{
		NodeType type;
		// ��ִ�н���֮���Ƿ���� free ����
		bool freeOnExeced;
		// ��ǰ�ڵ��ֵ .  �����ǰ�����һ���������֣� ��free ��ʱ���ʩ�����ֵ���ڴ�
		Object *value;
		// ����ָ�� �� ��Ҫ���ڷ��ò���ʲô��
		void *ptr_u;
		// �ڵ�״̬
		NodeState state;
		// ����ֵ �� �����ǰ�ڵ�Ϊһ�� �����ڵ㣬 ��ǰ������Ϊ����
		Object *postposition;

		Variable *var_obj;
		Constant *con_obj;
		Operator *opr_obj;
	};

	// �����б� ,��󲻳���30������
	struct ParamsList
	{
		char* args[PARAM_COUNT];
		// ��������
		int index;
	};

	// ����ʵ��
	struct ArgsList
	{
		Node *args[PARAM_COUNT];
		// ʵ������
		int index;
	};

	struct X3rdArgs
	{
		Object *args[PARAM_COUNT];
		// ʵ������, һ���ʾ ������
		int index;
	};
}