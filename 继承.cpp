#include"func.h"




//�̳��У������ڹ����ʱ���ȹ��츸��
//������ʱ�����������࣬����������

class Base1 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1 {
public:
	void func()
	{				// Son1 ͨ�� ���м̳�
		m_A = 1;	//����Ĺ������ԣ�����������Ȼ�ǹ�������
		m_B = 2;	//����ı���Ȩ�޳�Ա������������Ȼ��
		//m_C = 3;	//�����е���˽Ȩ�޳�Ա�������޷�����
	}

};

void test23()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 200; //������Ա�������޷�����
	cout << "test23 s1.m_A=" << s1.m_A << endl;
	
}

class Son2 :protected Base1 {
	void func()
	{				// Son1 ͨ�� �����̳�
		m_A = 11;	//����Ĺ������ԣ����������Ϊ����Ȩ��
		m_B = 22;	//����ı���Ȩ�޳�Ա������������Ȼ��
		//m_C = 33;	//�����е���˽Ȩ�޳�Ա�������޷�����
	}
};

void  test24()
{
	Son2 s2;
	//s2.m_A = 1;	//�����̳к󣬻���Ĺ���/���� ��Ա����Ϊ ������Ա�������޷�����
}
class Son3 :private Base1 {
	void func()
	{				// Son1 ͨ�� �����̳�
		m_A = 111;	//����Ĺ������ԣ����������Ϊ˽��
		m_B = 222;	//����ı���Ȩ�޳�Ա�����������Ϊ˽��
		//m_C = 333;	//�����е���˽Ȩ�޳�Ա�������޷�����
	}
};

class Grand3 :public Son3 {
	void func()
	{				// Grand3 ͨ�� �����̳�
		//m_A = 111;	//Son3��ͨ��˽�м̳з�ʽ�̳�Base1�ģ�����Son3�����м̳���Base1�ĳ�Ա����˽�е�
		//m_B = 222;	//��� Grand3 ͨ��public ��ʽ�̳� Son3 Ҳ���޷������κ� Son3 �ĳ�Ա��
		//m_C = 333;	
	}
};


void test22()
{
	Son1 s1;
	

	Son2 s2;

	
	Son3 s3;

}










class Base2 {
public:
	//Base2()
	//{
	//	m_A = 1;
	//	A1 = 2;
	//	m_B = 3;
	//	m_C = 4;
	//}
	//
	void func()
	{
		cout << "Based2 b21.A1(��̬��Ա) ��ַ=" << (int)&A1 << endl;
	}
	
	int m_A;
	static int A1;
protected:
	int m_B;
private:
	int m_C;
};

//��̬��Ա��ʼ�� Ҫ�� ����
int Base2::A1 = 0;

class Son21 :public Base2 {
public:
	int m_D;
	int m_E;
};
void test25(void)
{
	Base2 b21;
	cout << "Base2 b21 siozeof(b21)=" << sizeof(b21) << endl;

	Son21 s21;	//�����̳и��������зǾ�̬��Ա,��̬��Ա��û�б��̳�,��̬��Ա������������������
	cout << "Son21 s21 sizeof(s21)=" << sizeof(s21) << endl;
	cout << "Son21 s21 ��ַ=" <<(int)&s21 << endl;
	b21.func();
}


//���� ������Ա������ʾ���� �鿴������ģ�͡�   ������vs2019�Ŀ�ʼ�˵��£�Developer Command Prompt For VS 2019
//ʹ�� "cd ../" �ص�C�� ��Ŀ¼
//���� ��E:������E�̣�Ȼ�� cd �е�Դ�ļ������ļ��С�
//���� ��c1 /d1 reportSingleClassLayout���� �ļ�����
//eg: "cl /d1 reportSingleClassLayoutBase2 �̳�.cpp"  Base2������

/*	�������ͼ��ʾ����test28�Ĳ������ݣ�
E:\VS\���� > cl / d1 reportSingleClassLayoutwulin �̳�.cpp
���� x86 �� Microsoft(R) C / C++ �Ż������� 19.29.30040 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

�̳�.cpp

class wulin     size(24) :
	+-- -
	0 | +-- - (base class Benz)
	0      | | +-- - (base class Car)
	0      | | | c_price
	| | +-- -
	4      | | c_price
	8      | | Mei
	| +-- -
	12 | +-- - (base class Bwm)
	12      | | +-- - (base class Car)
	12      | | | c_price
	| | +-- -
	16      | | baoma
	| +-- -
	20 | wu
	+ -- -

*/
/*
E:\VS\���� > cl / d1 reportSingleClassLayoutwulin1 �̳�.cpp
���� x86 �� Microsoft(R) C / C++ �Ż������� 19.29.30040 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

�̳�.cpp

class wulin1    size(24) :					// vbptr�� virtual base table pointer
	+-- -									// v��virtual
	0 | +-- - (base class Benz1)			// b��base
	0      | | {vbptr}						// ptr��pointer
4      | | Mei
| +-- -
8 | +-- - (base class Bwm1)
8      | | {vbptr}
12      | | baoma
| +-- -
16 | wu
+ -- -
+-- - (virtual base Car1)
20 | c_price
+ -- -

wulin1::$vbtable@Benz1@:
0 | 0
1 | 20 (wulin1d(Benz1 + 0)Car1)

wulin1::$vbtable@Bwm1@:
0 | 0
1 | 12 (wulin1d(Bwm1 + 0)Car1)
vbi : class  offset o.vbptr  o.vbte fVtorDisp
Car1      20       0       4 0
*/

/*�̳��У�ͬ����Ա�Ĵ���*/
//======================
class Base3
{
public:
	Base3()
	{
		m_a = 2;
	}
	void func()
	{
		cout << "Base3 func is used !" << endl;
	}

	void func(int f)
	{
		cout << "Base3 func is used ! �� f= " <<f<< endl;
	}
	int m_a;
};

class Son31:public Base3
{
public:
	Son31()
	{
		m_a = 3;
	}
	void func()
	{
		cout << "Son31 func is used !" << endl;
	}
	int m_a;
};

void test26()
{
	Son31 s31;
//��/���� ������/��Ա ͬ��ʱ�� ���������ʸ������� ��Ա/��������Ҫ�ڡ� . �� ��������֮����������� �� ������:: ��������ʾ
	cout << "Son31ֱ�ӵ����������ࣩ��m_a  s31.m_a=" << s31.m_a << "  Son31���ʸ����е�m_a   s31.Base3::m_a=" << s31.Base3::m_a << endl;
	s31.func();	//������� ���� ��ͬ������
	s31.Base3::func();//������� ���� ��ͬ������
	s31.Base3::func(31); // ������� ���� ��ͬ�������������е����غ�����

}


class Base4
{
public:
	int m_a;
	static int m_b;
	static void func()
	{
		cout << "Base4 �� static func ��" << endl;
	}

};
int Base4::m_b = 41;
class Son41 :public Base4
{
public:
	int m_c;
	static int m_b;
	static void func()
	{
		cout << "Son41 �� static func ��" << endl;
	}
};
int Son41::m_b = 411;

class Son42 :public Base4
{
public:
	int m_d;
	static int m_b;
	static void func()
	{
		cout << "Son41 �� static func ��" << endl;
	}
	void set_father_static(int a)
	{
		Base4::m_b = a;
		cout << "Son42 �� set_father_static  " << endl;
	}
};
int Son42::m_b = 411;

void test27(void)
{
	Son41 s41;
	cout << " Son41��m_b=" << s41.m_b << "  Base41��m_b=" <<s41.Base4::m_b <<endl;

	s41.func();
	s41.Base4::func();
	

	Son42 s42;
	s42.set_father_static(422);
	cout<<"Son41�鿴 Base4 ��m_b=" << s41.Base4::m_b << endl;
	cout<<"Base4��m_b=" << Base4::m_b << endl;	//ͨ���������� ��̬��Ա
	cout <<"Base4��m_b=" << Son41::Base4::m_b << endl;	//ͨ���������ʡ���һ��::  ����������ʽ���ʣ��ڶ���;;  ������ʸ���������
	Son41::Base4::func();
}





//���Σ���ʯ���̳�
	//		father			Father: Car
	//		/	\
	//	   /	 \
	//	 /		  \
	//	Son1	son2		son1:Benz   son2:Bwm
	//	\		  /
	//	 \		 /
	//	  \		/
	//	   Grand			Grand : wulin
class Car
{
public:

	int c_price=10;
};

class Benz :public Car
{
public:
	int c_price=100;
	int Mei=4;
};

class Bwm :public Car
{
public:
	int baoma=7;
};

class wulin :public Benz, public Bwm
{
public:
	int wu=1;
};

void test28(void)
{
	wulin w1;
	cout << w1.Benz::Car::c_price << endl;	//Benz �� Car ��ͬ����c_price��Ա������wulin���� Car ���ϵ�c_price����Ҫ��ȷ��Car��
	cout << w1.Bwm::c_price << endl;	//Bwm û�к� Car ͬ����c_price��Ա������wulin���� Car ���ϵ�c_priceֻ��Ҫ��ȷ��Bwm��
}


//��̳� ��� ���μ̳д����� ���������⡣
class Car1
{
public:

	int c_price = 10;
};

class Benz1 :virtual public Car1	//���virtual��ʹ�� �̳� ��� ��̳У�Car���� �����
{									//������ʹ�ü̳м̳������������ࣨ�����̳���������࣬Ҳ�������ӣ�
									//������ ͬһ�� ���ݣ��൱�ھ�̬�����ˡ��������������ݻ��Ǳ�������һ��
									//��˼���������๲�� ͬһ�� ���� �ĸ���
public:
	int Mei = 4;
};

class Bwm1 :virtual public Car1
{
public:
	int baoma = 7;
};

class wulin1 :public Benz1, public Bwm1
{
public:
	int wu = 1;
};

void test29(void)
{
	cout << "test29 start!!!!!!!!" << endl;
	wulin1 w11;
	Car c1;
	cout << "ͨ�� w11.Benz1  ��� Car �� c_price=" << w11.Benz1::c_price << endl;
	w11.c_price = 1000000;
	Bwm1 bw1;
	w11.Bwm1::c_price = 200000;
	cout << "ͨ�� w11 �޸� Car �� c_price" << endl;
	cout << "��� Car �� c_price = " << c1.c_price << endl;
	cout << "ͨ�� Benz1 ��� Car �� c_price=" << w11.Benz1::c_price << endl;
	cout << "ͨ�� Bwm1 ��� Car �� c_price=" << w11.Bwm1::c_price << endl;
	cout << "��� Car �� c_price = " << c1.c_price << endl;
}