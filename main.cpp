#include"func.h"

//C++���������ٸ�һ�������4������
//Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
//Ĭ�������������޲Σ�������Ϊ�գ�
//Ĭ�Ͽ������캯���������Խ��� ֵ����
//��ֵ����� operator= ��������ֵ���п���

//�������������ָ����� ���ͻ���� ��ǳ���� ����������

class Person
{
public:
	Person()//���캯�����ܷ���˽������
	{		//�޲ι��캯�� �� �����ڲ������� ��һ���֮ΪĬ�Ϲ��캯��
		cout << "Person�� �޲� ���캯��������" << endl;
	}

	Person(int a)//�вι��캯��
	{		
		p_a = a;
		cout << "Person�� �в� ���캯��������" << endl;
	}

	Person(const Person& p)//�������캯��, ��ʵ(Person *p)Ҳ�ǿ��Եģ���const�Ƚϱ�׼
	{
		p_a = p.p_a;
		cout << "Person�� ���� ���캯��������" << endl;
	}

	~Person()
	{

		cout << "Person����������������" << endl;
	}
	int p_a;

private:
	

};
void test01(void)//���ŷ� ���ù��캯��
{
	//����ʵ�����һ���ֲ�����Ĵ����ں�������ʱ�����������ź�������������
	cout << endl;
	cout << "test 01 start !!!" << endl;
	Person p2;		//Ĭ�ϣ��޲Σ����캯��  �ĵ��ã����ܼӣ�������Ȼ����������Ϊ p2���� ��һ����������

	Person P1(1);	//�вι���  �����ĵ���
	Person P2(P1);	//�������� �ĵ���
	cout << "P1:" << P1.p_a << endl;
	cout << "P2:" << P2.p_a << endl;

	cout << "test 01 endl !!!" << endl;
	cout  << endl;
}

void test02(void)//��ʾ�� ���ù��캯��
{
	cout << endl;
	cout << "test 02 start !!!" << endl;
	Person p3;		//Ĭ�ϣ��޲Σ����캯��  �ĵ���

	Person P4=Person(1);	//�вι���  
	Person P5=Person(P4);	//�������� 
	cout << "P4:" << P4.p_a << endl;
	cout << "P5:" << P5.p_a << endl;

	cout << "test 02 endl !!!" << endl;
	cout << endl;
}

void test03(void)//��ʽת���� ���ù��캯��
{
	cout << endl;
	cout << "test 03 start !!!" << endl;

	Person P8 = 88;	//�вι���  // Person P8 = Person(88)
	Person P9 = P8;	//�������� 
	cout << "P8:" << P8.p_a << endl;
	cout << "P9:" << P9.p_a << endl;

	cout << "test 03 endl !!!" << endl;
	cout << endl;
}

void test04(Person p)
{
}
void test05(void)	//ֵ���ݷ�ʽ������������ֵ
{

	cout << "test 05 start !!!" << endl;
	Person p;	//�������Ĭ�Ϲ��캯��
	test04(p);	//������ֵ���ݣ���p������test04���β��ϣ�ʹ�� ���� ����
	cout << "test 05 endl !!!" << endl;
}

Person test06()
{
	cout << "test 06 start !!!" << endl;
	Person p;
	cout << "test 06 ��p�ĵ�ַ��" << (int *)&p << endl;//���� * ����ӡ�ľ���16���ƣ����ӣ�����10���ơ�
	cout << "test 06 endl !!!" << endl;
	return p;
}

void test07()	//ֵ��ʽ���ؾֲ�����
{
	cout << "test 07 start !!!" << endl;
	Person p = test06();
	cout << "test 07 ��p�ĵ�ַ��" << (int *)&p << endl;
	cout << "test 07 endl !!!" << endl;
}


//ǳ������ֱ��һ��һ�����ݸ��ƹ�ȥ��Ŀ�����
//��������¿���һ��ռ䣬�����ݸ��Ƶ�Ŀ�����

int main()
{
	test01();
	test02();
	test03();
	cout << "��������ĳ�ʼ��" << endl;//�������ɣ�֮����������
	Person(33);	//��Ҫʹ�� �������� ��ʼ��һ���������󣬱���������Ϊ Person(p2)==��Person p2, ��������
	cout << "��������Ľ���" << endl;

	test05();
	test07();

	test10();

	test13();

	test14();

	test15();

	test16();

	test18();

	test25();

	test26();

	test27();

	test28();

	test29();

	test30();

	test31();

	test32();

	test34();

	system("pause");
	return 0;
}