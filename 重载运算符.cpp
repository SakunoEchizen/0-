#include"func.h"

class Person
{
public:
	int m_a;
	int m_b;
	//Person operator+(Person& p)//��Ա���� ���� + �����
	//{
	//	Person tmp;
	//	tmp.m_a=this->m_a + p.m_a;
	//	tmp.m_b=this->m_b + p.m_b;
	//	return tmp;
	//}

	 //�����ڳ�Ա������������ << �����,��Ϊ��ʹ�õ��÷�ʽ��ɡ� p4<< cout;����cout������Ҳ���
		#if 0
			ostream& operator<< (ostream& cout)//�ڳ�Ա������������ << 
			{									
				cout << "m_a=" << this->m_a << "   m_b=" << this->m_b << endl;
				return cout;		
			}
		#endif
};

Person operator+(Person& p1, Person& p2)//ȫ�ֺ��� ���� + �����
{
	Person tmp;
	tmp.m_a = p2.m_a + p1.m_a;
	tmp.m_b = p2.m_b + p1.m_b;
	return tmp;
}

//cout����ostream����
ostream & operator<< (ostream &cout,Person &p )//������operator<<(cout,p),  ���� cout<<p
{										//ʹ��ȫ�ֺ��������� << �����
	cout << "m_a=" << p.m_a << "   m_b=" << p.m_b << endl;
	return cout;		//������Ҫ��cout<<p<<endl;������ô��Ҫ��opsrator֮ǰ���� ��ostream &����ʹ�÷��� cout��
						//ͬʱû��Ҳ��cout,ԭ����ʽ����ķ�ʽ��Ҫ�з��صĶ�����ܳ������
	//�����coutֻ��һ��������д�� out Ҳ��
}




class myInt {
public:
	int m_int=0;

	//���� ǰ��++ �����  ����������Ϊ��һֱ�ԡ�һ�������ݽ��е���
	//myInt & operator++()
	//{
	//	//�ȵ���
	//	this->m_int++;
	//	//�ٽ�������
	//	return *this;	//ǰ�õ������ص��� ����
	//}


	//���� ����++ �����  ������ ռλ���� ���ֺ���һ������������
	myInt operator++( int )
	{
		//�ȼ�¼��ʱ�Ľ��
		myInt tmp = *this;
		 //�����
		this->m_int++;
		return tmp;//���õ������ص���ֵ���´�����һ��������������¼�ľ��� �Լ� ֮ǰ�����ݣ�
	}

};

ostream& operator<<(ostream& cout, myInt i)//�����i����������Ϊ�˺���� i2++
{					//i2++���ﷵ�ص��Ǿֲ�����tmp���ֲ���������������
	cout << "���ص�<< ,Ϊ�����myInt  "<<i.m_int;
	return cout;
}


class Human {	
public:
	int* m_age;
	Human() {}
	Human(int age)
	{
		m_age = new int(age);
	}

	~Human()
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}

	Human& operator= (Human & h)	//���� = ��Ϊ�˽�� ϵͳĬ�Ͽ������캯�� ������ ǳ���� ���⣨�����ظ��ͷţ�
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		//Human tmp;
		//tmp.m_age = new int(*h.m_age);
		m_age = new int(*h.m_age);
		return *this;

		
	}

};

class Tom {
public:
	int m_age;
	int m_id;

	Tom(int age, int id) :m_age(age), m_id(id) {}

	bool operator==(Tom &t)//��ϵ����� == ����   ���У�=��>, �����Ĺ�ϵ�����
	{
		if (this->m_age != t.m_age || this->m_id != t.m_id)
		{
			return false;
		}
		return true;
	}

};



class myPrint {
public:
	//���غ������������������Ҳ����С���ţ�������Ҳ���������غ�������Ϊ �º���
	void operator()(string str)
	{
		cout << "���غ������������  " << str << endl;
	}
};

void test21()
{
	myPrint p1;
	p1("Hello world");

	myPrint()("�����������");//�������������� myPrint() ����ִ����һ���ʱ��ͱ��ͷ���
}
void test20()
{
	//
	cout << "test20 start!!!!!!!!" << endl;
	Tom t1(1, 1);
	Tom t2(4, 4);
	Tom t3(4, 4);
	if (t1 == t2)
	{
		cout << "t1=t2 !!!!!!!!" << endl;
	}
	else
	{
		cout << "t1����t2 !!!!!!!!" << endl;
	}

	if (t3 == t2)
	{
		cout << "t3=t2 !!!!!!!!" << endl;
	}
	else
	{
		cout << "t3����t2 !!!!!!!!" << endl;
	}
}
void test19()
{
	cout << "test19 start!!!!!!!!" << endl;
	Human h1(18);
	cout << "h1�����䣺" << *h1.m_age << endl;

	Human h2(13);
	Human h3;

	h2 = h1;
	cout << "h2�����䣺" << *h2.m_age << endl;
	cout << "h2�����䣺" << *h2.m_age << endl;
	cout << "h2�����䣺" << *h2.m_age << endl;


	h3 = h2 = h1;	//���� = 
	cout << "h3�����䣺" << *h3.m_age << endl;


	test20();
}
void test18()
{
	cout << "test18 start!!!!!!!!" << endl;
	Person p1,p2;
	p1.m_a = 1;
	p1.m_b = 11;
	p2.m_a = 24;
	p2.m_b = 33;
	//Person p3 = p1 + p2;	//��Ա�������صı��ʣ� Person p3=p1.operator+(p2)
	cout << "p1,m_a=" << p1.m_a << "  p1.m_b=" << p1.m_b << endl;
	cout << "p2,m_a=" << p2.m_a << "  p2.m_b=" << p2.m_b << endl;
	//cout << "p3,m_a=" << p3.m_a << "  p3.m_b=" << p3.m_b << endl;

	p2.m_a = 29;
	p2.m_b = 39;
	cout << "p2,m_a=" << p2.m_a << "  p2.m_b=" << p2.m_b << endl;
	Person p4 = p1 + p2;	//ȫ�ֺ������صı��ʣ� Person p3=p1.operator+(p2)
	cout << "p4,m_a=" << p4.m_a << "  p4.m_b=" << " ������ + �������" << p4.m_b << endl;

	cout << p4;
	cout << "�ָ���---------------"<< endl;
	cout << p4 <<" ������ << �������"<< endl;


	
	
		//myInt i1;
		//cout << ++i1 << endl;
		//cout << i1 << endl;


		myInt i2;	//���غ���++
		cout << i2++ << endl;
		cout << i2 << endl;


		test19();	//���� =

		test21();//���غ������������

		cout <<"===========over============"<< endl;
}


