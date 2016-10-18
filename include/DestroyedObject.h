#pragma once


namespace langX {

	/* @date  2016-10-18 ���
	   @desc  �����յ�ϵͳ���� �������ö������������  ��� ����a ���û��ֶ�������delete ������ ��ô ����ָ��a�����ö������������
	*/

	class Object;

	//  �����ٵĶ��� 
	class DestroyedObject : public Object
	{
	public:
		DestroyedObject();
		~DestroyedObject();


		/* ��ǰֵ���Ա�ʾΪ��ô��  null,0,false �������ʾΪ��  */
		bool isTrue() const ;
		/* ��õ�ǰ���������  */
		ObjectType getType() const ;
		/* ��¡��ǰ���� ���س�һ���µĶ��� */
		Object* clone() const ;


		/* ���Լ�Update ��Ŀ���ֵ
		���������Ӧ�ã� Ҳ����update ���ڵĻ���   */
		void update(Object *) ;


	private:

		// ��������
		void finalize();

	};

}