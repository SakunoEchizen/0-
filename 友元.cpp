#include"func.h"

//友元的目的是是让 函数 或者 类 可以访问另一个类Home的私有成员！

//在编写的时候注意，被访问的类（Home）需要先在其他类之前声明，其他类之后实现。
//其他类的函数实现需要在 被访问类 实现之后 实现（也就是说，其他类的函数方法都在类外写，且在 被访问类实现 的后面
class Home;

class Building {
public:
	Building();
	Home *home;//当类中出现其他类的指针时，初始化的时候需要先为这个其他类申请一块空间，供其初始化，而指针则指向这块空间

	void visit();
private:

};

class BB {
public:
	BB();
	Home* home;//当类中出现其他类的指针时，初始化的时候需要先为这个其他类申请一块空间，供其初始化，而指针则指向这块空间

	void visit1();

	void putong_visit();
private:

};

class Home {
	friend void GoodFriend(Home* fri);	//声明  全局友元函数
	friend class Building;				//声明  友元类
	friend void BB::visit1();			//声明  友元 成员函数..告诉编译器，BB类中的成员函数 visit1 作为 本类 的友元函数
public:
	string H_dating = "大厅";

private:
	string H_bedroom = "卧室";


};

Building::Building() { home = new Home; }

void GoodFriend(Home *fri)//全局友元函数
{
	cout << "好朋友进入" << fri->H_dating << endl;
	cout << "好朋友进入" << fri->H_bedroom << endl;

}

BB::BB() { home = new Home; }
void BB::visit1()
{
	cout << "好朋友进入" << home->H_dating << endl;
	cout << "好朋友进入" << home->H_bedroom << endl;
}

void BB::putong_visit()
{
	cout << "好朋友进入" << home->H_dating << endl;
	//cout << "好朋友进入" << home->H_bedroom << endl;
}
void Building::visit()
{
	cout << "好朋友进入" << home->H_dating << endl;
	cout << "好朋友进入" << home->H_bedroom << endl;
}


void test14()
{
	cout << "test14 start!!!!!!!!" << endl;
	cout << "友元 全局函数" << endl;
	Home h1;
	GoodFriend(&h1);
}

void test15()
{
	cout << "test15 start!!!!!!!!" << endl;
	cout << "友元 类 " << endl;
	Building b1;
	
	b1.visit();
	delete b1.home;
}

void test16()
{
	cout << "test16 start!!!!!!!!" << endl;
	cout << "友元 成员函数  " << endl;
	BB b1;
	b1.visit1();
}