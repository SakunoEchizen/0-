#include"func.h"

//多态分为两类
 //静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
 //动态多态 : 派生类和虚函数实现运行时多态
//区别：
//* 静态多态的函数地址早绑定 - 编译阶段确定函数地址	早绑定
//* 动态多态的函数地址晚绑定 - 运行阶段确定函数地址	晚绑定

//动态多态的条件：1.继承关系  2.子类重写父类的虚函数
//动态多态的使用方式：父类的指针或者引用，执行子类的对象

//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护


/*不加 virtual ，animal对象的大小是1，加了是4，类的内部结构变化了，不再是空，多了一个指针
class Animal
{
public:
	virtual void speak()		
	{
		cout << "动物在说话 ！"<<endl;
	}
};
*/


class Animal
{
public:
	virtual void speak()		//添加了 virtual 后，变为虚函数，使得变成了晚绑定
	{
		cout << "动物在说话 ！"<<endl;
	}
};

class Cat :public Animal
{
public:
	 void speak()	//重写了父类的speak函数（虚函数） ，动态多态条件之一
	{			
		cout << "小猫 喵喵喵！" << endl;
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
	doSpeak(cat1);//doSpeak内的ani.speak（）是早绑定，所以只会调用Animal里的speak。
					//C++支持父子类转换，此时cat向上转成父类，所以调用的是Animal的。
					//要使得可以用doSpeak可以调用猫的，那么在Animal的speak前面加上virtual，变为晚绑定


	cout << endl;
}