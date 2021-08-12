#include"func.h"


//��ͳ��������ʵ�ַ�ʽ
class Calculator
{
public:
	float getResult(string op)
	{
		if (op == "+")
		{
			return n1 + n2;
		}
		else if ("-" == op)
		{
			return n1 - n2;
		}
		else if ("*" == op)
		{
			return n1 * n2;
		}
		else if ("/" == op)
		{
			
			return chufa();
		}
	}
	float chufa()
	{
		float a = n1 / n2;
		float b = (int)n1 % (int)n2;
		float c = a + b;
		return c;
	}
	Calculator(float a, float b) :n1(a), n2(b) {}
	float n1;
	float n2;

};



class abstractCalculator
{
public:
	float n1;
	float n2;
	//virtual float getResult() { return 0; }	//�麯��д��
	virtual float getResult() = 0;	//���� ���麯�� ������ֻҪ�д��麯������ô������һ��������
									//���������д�������еĴ��麯��������Ҳ���ڳ�����
									//������ �޷�ʵ�������󣬵����Զ���ָ��
};

class AddGet :public abstractCalculator
{
	float getResult()
	{
		return n1 + n2;
	}
};

class chufaGet :public abstractCalculator
{
	float getResult()
	{
		float a = n1 / n2;
		float b = (int)n1 % (int)n2;
		float c = a + b;
		return c;
	}
};








void test31(void)
{

	cout << "\ntest31 start!!!!!!!!\n" << endl;

	//��ͳ��������ʵ�ַ�ʽ
	Calculator c1(10, 3);
	cout<<"�����"<<c1.getResult("/") << endl;


	//��̬����д��1
	//abstractCalculator ads; //��ɳ�����֮���޷�ʵ��������
	AddGet add1;
	chufaGet chufa1;
	abstractCalculator *p=&add1;//��ɳ�����֮�󣬿��Զ���ָ��
	p->n1 = 10;
	p->n2 = 3;
	cout <<"д��1 ��̬������ �ӷ���" << p->getResult() << endl;
	p = &chufa1;
	p->n1 = 10;
	p->n2 = 3;
	cout << "д��1 ��̬������ ������" << p->getResult() << endl << endl;;

	//��̬����д��2����1Ч��һ�£�д���ϵĲ�ͬ
	abstractCalculator* p2 = new AddGet;
	p2->n1 = 10;
	p2->n2 = 3;
	cout << "д��2 ��̬������ �ӷ���" << p2->getResult() << endl;
	delete p2;
	p2 = new chufaGet;
	p2->n1 = 10;
	p2->n2 = 3;
	cout << "д��2 ��̬������ ������" << p2->getResult() << endl;
	delete p2;


}






//��̬ʹ��ʱ����������������Կ��ٵ�  ����  ����ô����ָ�����ͷ�ʱ�޷����õ��������������
//�����ʽ���������е�����������Ϊ ������ ���� ��������

//�������ʹ����������ԣ�
//* ���Խ������ָ���ͷ��������
//* ����Ҫ�о���ĺ���ʵ��
//
//�������ʹ�����������*����Ǵ����������������ڳ����࣬�޷�ʵ��������

//���������û�н����ݿ��ٵ����������Բ�д ��/���� ��������


class A
{
public:
	A()
	{
		cout << "A  �� gou zao ��������" << endl;
	}
	virtual void speak() = 0;
	virtual ~A();//������������������������ virtual ~A()=0; 
				//���������鹹������Ҫд��������ʵ�֣���ʹʵ���ڲ�������
				//�麯��������ʵ�ֿ�������д��	virtual ~A(){}  ����ʵ��
				//������������Ҫ������ʵ�֡�
};

 A::~A()
{
	// cout << "class A is delete!!" << endl;
}
class B :public A
{
public:
	B(string name)
	{
		cout << "B  �� ���� ��������" << endl;
		b_name =new string(name);
	}
	virtual void speak()
	{
		cout << "this is B class! " <<*b_name<< endl;
	}
	string* b_name;

	~B()
	{
		if (b_name != NULL)
		{
			cout << "class B is delete!!!" << endl;

			delete b_name;
			b_name = NULL;
		}
	}
};

void test32(void)
{
	cout << "\ntest 32 start!!!!!!!!\n" << endl;
	A * p = new B("Yom");
	p->speak();
	delete p;

}

