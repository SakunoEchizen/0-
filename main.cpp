#include"func.h"

//C++编译器至少给一个类添加4个函数
//默认构造函数（无参，函数体为空）
//默认析构函数（无参，函数体为空）
//默认拷贝构造函数，对属性进行 值拷贝
//赋值运算符 operator= ，对属性值进行拷贝

//如果类中有属性指向堆区 ，就会出现 深浅拷贝 带来的问题

class Person
{
public:
	Person()//构造函数不能放在私有区域
	{		//无参构造函数 且 函数内不做操作 ，一般称之为默认构造函数
		cout << "Person的 无参 构造函数！！！" << endl;
	}

	Person(int a)//有参构造函数
	{		
		p_a = a;
		cout << "Person的 有参 构造函数！！！" << endl;
	}

	Person(const Person& p)//拷贝构造函数, 其实(Person *p)也是可以的，用const比较标准
	{
		p_a = p.p_a;
		cout << "Person的 拷贝 构造函数！！！" << endl;
	}

	~Person()
	{

		cout << "Person的析构函数！！！" << endl;
	}
	int p_a;

private:
	

};
void test01(void)//括号法 调用构造函数
{
	//这里实验的是一个局部对象的创建在函数调用时创建，会随着函数结束而销毁
	cout << endl;
	cout << "test 01 start !!!" << endl;
	Person p2;		//默认（无参）构造函数  的调用，不能加（），不然编译器会认为 p2（） 是一个函数声明

	Person P1(1);	//有参构造  函数的调用
	Person P2(P1);	//拷贝构造 的调用
	cout << "P1:" << P1.p_a << endl;
	cout << "P2:" << P2.p_a << endl;

	cout << "test 01 endl !!!" << endl;
	cout  << endl;
}

void test02(void)//显示法 调用构造函数
{
	cout << endl;
	cout << "test 02 start !!!" << endl;
	Person p3;		//默认（无参）构造函数  的调用

	Person P4=Person(1);	//有参构造  
	Person P5=Person(P4);	//拷贝构造 
	cout << "P4:" << P4.p_a << endl;
	cout << "P5:" << P5.p_a << endl;

	cout << "test 02 endl !!!" << endl;
	cout << endl;
}

void test03(void)//隐式转换法 调用构造函数
{
	cout << endl;
	cout << "test 03 start !!!" << endl;

	Person P8 = 88;	//有参构造  // Person P8 = Person(88)
	Person P9 = P8;	//拷贝构造 
	cout << "P8:" << P8.p_a << endl;
	cout << "P9:" << P9.p_a << endl;

	cout << "test 03 endl !!!" << endl;
	cout << endl;
}

void test04(Person p)
{
}
void test05(void)	//值传递方式给函数参数传值
{

	cout << "test 05 start !!!" << endl;
	Person p;	//这里调用默认构造函数
	test04(p);	//这里是值传递，将p拷贝到test04的形参上，使用 拷贝 构造
	cout << "test 05 endl !!!" << endl;
}

Person test06()
{
	cout << "test 06 start !!!" << endl;
	Person p;
	cout << "test 06 ，p的地址：" << (int *)&p << endl;//加了 * ，打印的就是16进制，不加，就是10进制。
	cout << "test 06 endl !!!" << endl;
	return p;
}

void test07()	//值方式返回局部对象
{
	cout << "test 07 start !!!" << endl;
	Person p = test06();
	cout << "test 07 ，p的地址：" << (int *)&p << endl;
	cout << "test 07 endl !!!" << endl;
}


//浅拷贝：直接一对一将数据复制过去到目标对象
//深拷贝：重新开辟一块空间，将数据复制到目标对象

int main()
{
	test01();
	test02();
	test03();
	cout << "匿名对象的初始化" << endl;//马上生成，之后立即析构
	Person(33);	//不要使用 拷贝构造 初始化一个匿名对象，编译器会认为 Person(p2)==》Person p2, 对象声明
	cout << "匿名对象的结束" << endl;

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