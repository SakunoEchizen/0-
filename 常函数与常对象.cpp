#include"func.h"

class Teacher
{
public:
	int t_age;
	//const int t_id=123;//��ĳ�����Աֻ���������ڳ�ʼ��
	mutable int weight;// mutable ���εĳ�Ա���ڳ�����֮��Ҳ�����޸�

	void set_age(int age)
	{
		
		t_age = age;
		cout << "��ͨ������������Ϊ��" << t_age << endl;
	}
	void show_age() const
	{
		//t_age = 10;  //������ �ڲ������޸ĳ�Ա����
					//�� t_id �ǳ��������Ը��������޸���
		//t_age=10,�൱�� this->t_age=10, 
		//thisָ��ı�����ָ�볣�������ܸ���ָ��Ķ��󣬿��Ը���ָ������ֵ
		// this=NULL; ��㱨�����䵽this����ʱ���󣩡�
		//thisָ�뱾���� Teacher * const this
		//���� show_age() �������const֮���൱��const Teacher * const this�����ε���thisָ��
		//Ҳ����ָ���ָ��Ķ����ֵҲ�޷��ٴθ��ģ�
		//���� ��ͨ�� ��Ա���� t_age Ҳ�޷�����������ڱ��ı�



		cout << "�� ���� ��ʾ IDΪ��" << t_age << endl;
	}
	void set_weight(int wt) const
	{
		//�������ڿ����޸� mutable ���εĳ�Ա�����ĳ�Ա����
		weight = wt;
		cout << "�� ���� ���� mutable���ε� weight Ϊ��" << weight << endl;
	}
};

void test13()
{
	const Teacher t1;//�����������
	Teacher t2;
	//t1.set_age(100);	//������ ֻ���Ե��� ������
	t1.show_age();
	t1.set_weight(1);

	t2.set_age(100);//��ͨ������� ���� ������
	t2.set_weight(10);
	t2.show_age();
	
}