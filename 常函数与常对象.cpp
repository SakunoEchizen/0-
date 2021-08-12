#include"func.h"

class Teacher
{
public:
	int t_age;
	//const int t_id=123;//类的常量成员只可以在类内初始化
	mutable int weight;// mutable 修饰的成员，在常函数之外也可以修改

	void set_age(int age)
	{
		
		t_age = age;
		cout << "普通函数设置年龄为：" << t_age << endl;
	}
	void show_age() const
	{
		//t_age = 10;  //常函数 内不允许修改成员属性
					//而 t_id 是常量，所以更不可以修改了
		//t_age=10,相当于 this->t_age=10, 
		//this指针的本质是指针常量，不能更改指向的对象，可以更改指向对象的值
		// this=NULL; 会汇报“分配到this（记时错误）”
		//this指针本意是 Teacher * const this
		//当在 show_age() 后面加上const之后，相当于const Teacher * const this，修饰的是this指针
		//也就是指针的指向的对象的值也无法再次更改！
		//所以 普通的 成员变量 t_age 也无法在这个函数内被改变



		cout << "常 函数 显示 ID为：" << t_age << endl;
	}
	void set_weight(int wt) const
	{
		//常函数内可以修改 mutable 修饰的成员，它的成员属性
		weight = wt;
		cout << "常 函数 更改 mutable修饰的 weight 为：" << weight << endl;
	}
};

void test13()
{
	const Teacher t1;//常对象的声明
	Teacher t2;
	//t1.set_age(100);	//常对象 只可以调用 常函数
	t1.show_age();
	t1.set_weight(1);

	t2.set_age(100);//普通对象可以 调用 常函数
	t2.set_weight(10);
	t2.show_age();
	
}