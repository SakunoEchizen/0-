#include"func.h"

class Person
{
public:
	int m_a;
	int m_b;
	//Person operator+(Person& p)//成员函数 重载 + 运算符
	//{
	//	Person tmp;
	//	tmp.m_a=this->m_a + p.m_a;
	//	tmp.m_b=this->m_b + p.m_b;
	//	return tmp;
	//}

	 //不能在成员函数里面重载 << 运算符,因为会使得调用方式变成“ p4<< cout;”，cout变成在右侧了
		#if 0
			ostream& operator<< (ostream& cout)//在成员函数里面重载 << 
			{									
				cout << "m_a=" << this->m_a << "   m_b=" << this->m_b << endl;
				return cout;		
			}
		#endif
};

Person operator+(Person& p1, Person& p2)//全局函数 重载 + 运算符
{
	Person tmp;
	tmp.m_a = p2.m_a + p1.m_a;
	tmp.m_b = p2.m_b + p1.m_b;
	return tmp;
}

//cout属于ostream对象
ostream & operator<< (ostream &cout,Person &p )//本质是operator<<(cout,p),  简化是 cout<<p
{										//使用全局函数，重载 << 运算符
	cout << "m_a=" << p.m_a << "   m_b=" << p.m_b << endl;
	return cout;		//若是想要“cout<<p<<endl;”，那么需要在opsrator之前加上 “ostream &”，使得返回 cout；
						//同时没这也是cout,原本链式输出的方式，要有返回的对象才能持续输出
	//在这里，cout只是一个别名，写成 out 也行
}




class myInt {
public:
	int m_int=0;

	//重载 前置++ 运算符  返回引用是为了一直对“一个”数据进行递增
	//myInt & operator++()
	//{
	//	//先递增
	//	this->m_int++;
	//	//再将自身返回
	//	return *this;	//前置递增返回的是 引用
	//}


	//重载 后置++ 运算符  ，利用 占位参数 区分和上一个函数的重载
	myInt operator++( int )
	{
		//先记录当时的结果
		myInt tmp = *this;
		 //后递增
		this->m_int++;
		return tmp;//后置递增返回的是值，新创建的一个对象（这个对象记录的就是 自加 之前的内容）
	}

};

ostream& operator<<(ostream& cout, myInt i)//这里的i不加引用是为了后面的 i2++
{					//i2++这里返回的是局部变量tmp，局部变量不能用引用
	cout << "重载的<< ,为了输出myInt  "<<i.m_int;
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

	Human& operator= (Human & h)	//重载 = ，为了解决 系统默认拷贝构造函数 带来的 浅拷贝 问题（堆区重复释放）
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

	bool operator==(Tom &t)//关系运算符 == 重载   还有！=，>, 这样的关系运算符
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
	//重载函数调用运算符，，，也就是小括号（），，也称这种重载函数调用为 仿函数
	void operator()(string str)
	{
		cout << "重载函数调用运算符  " << str << endl;
	}
};

void test21()
{
	myPrint p1;
	p1("Hello world");

	myPrint()("匿名对象输出");//创建的匿名对象 myPrint() ，到执行下一句的时候就被释放了
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
		cout << "t1不等t2 !!!!!!!!" << endl;
	}

	if (t3 == t2)
	{
		cout << "t3=t2 !!!!!!!!" << endl;
	}
	else
	{
		cout << "t3不等t2 !!!!!!!!" << endl;
	}
}
void test19()
{
	cout << "test19 start!!!!!!!!" << endl;
	Human h1(18);
	cout << "h1的年龄：" << *h1.m_age << endl;

	Human h2(13);
	Human h3;

	h2 = h1;
	cout << "h2的年龄：" << *h2.m_age << endl;
	cout << "h2的年龄：" << *h2.m_age << endl;
	cout << "h2的年龄：" << *h2.m_age << endl;


	h3 = h2 = h1;	//重载 = 
	cout << "h3的年龄：" << *h3.m_age << endl;


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
	//Person p3 = p1 + p2;	//成员函数重载的本质： Person p3=p1.operator+(p2)
	cout << "p1,m_a=" << p1.m_a << "  p1.m_b=" << p1.m_b << endl;
	cout << "p2,m_a=" << p2.m_a << "  p2.m_b=" << p2.m_b << endl;
	//cout << "p3,m_a=" << p3.m_a << "  p3.m_b=" << p3.m_b << endl;

	p2.m_a = 29;
	p2.m_b = 39;
	cout << "p2,m_a=" << p2.m_a << "  p2.m_b=" << p2.m_b << endl;
	Person p4 = p1 + p2;	//全局函数重载的本质： Person p3=p1.operator+(p2)
	cout << "p4,m_a=" << p4.m_a << "  p4.m_b=" << " 重载了 + 运算符号" << p4.m_b << endl;

	cout << p4;
	cout << "分隔符---------------"<< endl;
	cout << p4 <<" 重载了 << 运算符号"<< endl;


	
	
		//myInt i1;
		//cout << ++i1 << endl;
		//cout << i1 << endl;


		myInt i2;	//重载后置++
		cout << i2++ << endl;
		cout << i2 << endl;


		test19();	//重载 =

		test21();//重载函数调用运算符

		cout <<"===========over============"<< endl;
}


