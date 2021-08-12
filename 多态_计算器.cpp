#include"func.h"


//传统计算器的实现方式
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
	//virtual float getResult() { return 0; }	//虚函数写法
	virtual float getResult() = 0;	//定义 纯虚函数 。类中只要有纯虚函数，那么他就是一个抽象类
									//子类必须重写抽象类中的纯虚函数，否则也属于抽象类
									//抽象类 无法实例化对象，但可以定义指针
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

	//传统计算器的实现方式
	Calculator c1(10, 3);
	cout<<"输出："<<c1.getResult("/") << endl;


	//多态调用写法1
	//abstractCalculator ads; //变成抽象类之后，无法实例化对象
	AddGet add1;
	chufaGet chufa1;
	abstractCalculator *p=&add1;//变成抽象类之后，可以定义指针
	p->n1 = 10;
	p->n2 = 3;
	cout <<"写法1 多态计算器 加法：" << p->getResult() << endl;
	p = &chufa1;
	p->n1 = 10;
	p->n2 = 3;
	cout << "写法1 多态计算器 除法：" << p->getResult() << endl << endl;;

	//多态调用写法2，与1效果一致，写法上的不同
	abstractCalculator* p2 = new AddGet;
	p2->n1 = 10;
	p2->n2 = 3;
	cout << "写法2 多态计算器 加法：" << p2->getResult() << endl;
	delete p2;
	p2 = new chufaGet;
	p2->n1 = 10;
	p2->n2 = 3;
	cout << "写法2 多态计算器 除法：" << p2->getResult() << endl;
	delete p2;


}






//多态使用时，如果子类中有属性开辟到  堆区  ，那么父类指针在释放时无法调用到子类的析构代码
//解决方式：将父类中的析构函数改为 虚析构 或者 纯虚析构

//虚析构和纯虚析构共性：
//* 可以解决父类指针释放子类对象
//* 都需要有具体的函数实现
//
//虚析构和纯虚析构区别：*如果是纯虚析构，该类属于抽象类，无法实例化对象

//如果子类中没有将数据开辟到堆区，可以不写 虚/纯虚 析构函数


class A
{
public:
	A()
	{
		cout << "A  的 gou zao 函数！！" << endl;
	}
	virtual void speak() = 0;
	virtual ~A();//这里是虚析构，纯虚析构： virtual ~A()=0; 
				//无论哪种虚构，都需要写出声明和实现，即使实现内不做操作
				//虚函数的声明实现可以这样写：	virtual ~A(){}  类内实现
				//纯虚析构函数要在类外实现。
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
		cout << "B  的 构造 函数！！" << endl;
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

