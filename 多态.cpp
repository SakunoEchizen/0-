#include"func.h"

//��̬��Ϊ����
 //��̬��̬: �������� �� ������������ھ�̬��̬�����ú�����
 //��̬��̬ : ��������麯��ʵ������ʱ��̬
//����
//* ��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ	���
//* ��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ	���

//��̬��̬��������1.�̳й�ϵ  2.������д������麯��
//��̬��̬��ʹ�÷�ʽ�������ָ��������ã�ִ������Ķ���

//��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��


/*���� virtual ��animal����Ĵ�С��1��������4������ڲ��ṹ�仯�ˣ������ǿգ�����һ��ָ��
class Animal
{
public:
	virtual void speak()		
	{
		cout << "������˵�� ��"<<endl;
	}
};
*/


class Animal
{
public:
	virtual void speak()		//����� virtual �󣬱�Ϊ�麯����ʹ�ñ�������
	{
		cout << "������˵�� ��"<<endl;
	}
};

class Cat :public Animal
{
public:
	 void speak()	//��д�˸����speak�������麯���� ����̬��̬����֮һ
	{			
		cout << "Сè ��������" << endl;
	}
};

void doSpeak(Animal& ani)
{
	ani.speak();
}

void test30(void)
{

	cout << "\ntest30 start!!!!!!!!\n" << endl;

	Cat cat1;	
	doSpeak(cat1);//doSpeak�ڵ�ani.speak��������󶨣�����ֻ�����Animal���speak��
					//C++֧�ָ�����ת������ʱcat����ת�ɸ��࣬���Ե��õ���Animal�ġ�
					//Ҫʹ�ÿ�����doSpeak���Ե���è�ģ���ô��Animal��speakǰ�����virtual����Ϊ���


	cout << endl;
}