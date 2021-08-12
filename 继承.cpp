#include"func.h"




//继承中，子类在构造的时候，先构造父类
//析构的时候，先析构子类，再析构父类

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
	{				// Son1 通过 公有继承
		m_A = 1;	//基类的公共属性，到了子类依然是公共属性
		m_B = 2;	//基类的保护权限成员，到了子类依然是
		//m_C = 3;	//父类中的隐私权限成员，子类无法访问
	}

};

void test23()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 200; //保护成员，类外无法访问
	cout << "test23 s1.m_A=" << s1.m_A << endl;
	
}

class Son2 :protected Base1 {
	void func()
	{				// Son1 通过 保护继承
		m_A = 11;	//基类的公共属性，到了子类变为保护权限
		m_B = 22;	//基类的保护权限成员，到了子类依然是
		//m_C = 33;	//父类中的隐私权限成员，子类无法访问
	}
};

void  test24()
{
	Son2 s2;
	//s2.m_A = 1;	//保护继承后，基类的共有/保护 成员都变为 保护成员。类外无法访问
}
class Son3 :private Base1 {
	void func()
	{				// Son1 通过 保护继承
		m_A = 111;	//基类的公共属性，到了子类变为私有
		m_B = 222;	//基类的保护权限成员，到了子类变为私有
		//m_C = 333;	//父类中的隐私权限成员，子类无法访问
	}
};

class Grand3 :public Son3 {
	void func()
	{				// Grand3 通过 公共继承
		//m_A = 111;	//Son3是通过私有继承方式继承Base1的，所以Son3中所有继承自Base1的成员都是私有的
		//m_B = 222;	//因此 Grand3 通过public 方式继承 Son3 也是无法访问任何 Son3 的成员的
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
		cout << "Based2 b21.A1(静态成员) 地址=" << (int)&A1 << endl;
	}
	
	int m_A;
	static int A1;
protected:
	int m_B;
private:
	int m_C;
};

//静态成员初始化 要在 类外
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

	Son21 s21;	//子类会继承父类中所有非静态成员,静态成员变没有被继承,静态成员函数是所有类对象共享的
	cout << "Son21 s21 sizeof(s21)=" << sizeof(s21) << endl;
	cout << "Son21 s21 地址=" <<(int)&s21 << endl;
	b21.func();
}


//利用 开发人员命令提示工具 查看“对象模型”   工具在vs2019的开始菜单下：Developer Command Prompt For VS 2019
//使用 "cd ../" 回到C盘 根目录
//输入 “E:”进入E盘，然会 cd 切到源文件所在文件夹。
//输入 “c1 /d1 reportSingleClassLayout类名 文件名”
//eg: "cl /d1 reportSingleClassLayoutBase2 继承.cpp"  Base2是类名

/*	输出如下图所示：（test28的测试内容）
E:\VS\对象 > cl / d1 reportSingleClassLayoutwulin 继承.cpp
用于 x86 的 Microsoft(R) C / C++ 优化编译器 19.29.30040 版
版权所有(C) Microsoft Corporation。保留所有权利。

继承.cpp

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
E:\VS\对象 > cl / d1 reportSingleClassLayoutwulin1 继承.cpp
用于 x86 的 Microsoft(R) C / C++ 优化编译器 19.29.30040 版
版权所有(C) Microsoft Corporation。保留所有权利。

继承.cpp

class wulin1    size(24) :					// vbptr： virtual base table pointer
	+-- -									// v：virtual
	0 | +-- - (base class Benz1)			// b：base
	0      | | {vbptr}						// ptr：pointer
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

/*继承中，同名成员的处理*/
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
		cout << "Base3 func is used ! 且 f= " <<f<< endl;
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
//父/子类 函数名/成员 同名时， 子类对象访问父类对象的 成员/函数，需要在“ . 和 对象名”之间加上作用域 “ 父类名:: ”，如下示
	cout << "Son31直接调用自身（子类）的m_a  s31.m_a=" << s31.m_a << "  Son31访问父类中的m_a   s31.Base3::m_a=" << s31.Base3::m_a << endl;
	s31.func();	//子类调用 自身 的同名函数
	s31.Base3::func();//子类调用 父类 的同名函数
	s31.Base3::func(31); // 子类调用 父类 的同名函数（父类中的重载函数）

}


class Base4
{
public:
	int m_a;
	static int m_b;
	static void func()
	{
		cout << "Base4 的 static func ！" << endl;
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
		cout << "Son41 的 static func ！" << endl;
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
		cout << "Son41 的 static func ！" << endl;
	}
	void set_father_static(int a)
	{
		Base4::m_b = a;
		cout << "Son42 的 set_father_static  " << endl;
	}
};
int Son42::m_b = 411;

void test27(void)
{
	Son41 s41;
	cout << " Son41的m_b=" << s41.m_b << "  Base41的m_b=" <<s41.Base4::m_b <<endl;

	s41.func();
	s41.Base4::func();
	

	Son42 s42;
	s42.set_father_static(422);
	cout<<"Son41查看 Base4 的m_b=" << s41.Base4::m_b << endl;
	cout<<"Base4的m_b=" << Base4::m_b << endl;	//通过类名访问 静态成员
	cout <<"Base4的m_b=" << Son41::Base4::m_b << endl;	//通过类名访问。第一个::  代表类名方式访问；第二个;;  代表访问父类作用域
	Son41::Base4::func();
}





//菱形（钻石）继承
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
	cout << w1.Benz::Car::c_price << endl;	//Benz 和 Car 有同名的c_price成员，子类wulin访问 Car 类上的c_price就需要明确到Car。
	cout << w1.Bwm::c_price << endl;	//Bwm 没有和 Car 同名的c_price成员，子类wulin访问 Car 类上的c_price只需要明确到Bwm。
}


//虚继承 解决 菱形继承带来的 二义性问题。
class Car1
{
public:

	int c_price = 10;
};

class Benz1 :virtual public Car1	//添加virtual，使得 继承 变成 虚继承，Car成了 虚基类
{									//虚基类会使得继承继承它的所有子类（包括继承子类的子类，也就是孙子）
									//都共享 同一份 数据，相当于静态变量了。但是虚基类的数据还是本来的那一份
									//意思是所有子类共享 同一份 基类 的副本
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
	cout << "通过 w11.Benz1  输出 Car 的 c_price=" << w11.Benz1::c_price << endl;
	w11.c_price = 1000000;
	Bwm1 bw1;
	w11.Bwm1::c_price = 200000;
	cout << "通过 w11 修改 Car 的 c_price" << endl;
	cout << "输出 Car 的 c_price = " << c1.c_price << endl;
	cout << "通过 Benz1 输出 Car 的 c_price=" << w11.Benz1::c_price << endl;
	cout << "通过 Bwm1 输出 Car 的 c_price=" << w11.Bwm1::c_price << endl;
	cout << "输出 Car 的 c_price = " << c1.c_price << endl;
}