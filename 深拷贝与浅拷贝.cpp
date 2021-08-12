#include"func.h"


class stu_ID
{
public:
	stu_ID() {}
	stu_ID(int id)
	{
		ID = id;
		cout << "ID是："<<id<<" 已经构造了" << endl;
	}
	void show_name()
	{
		cout << "this is name for NULL_P test!!" << endl;
	}
	void show_ID()
	{
		if (NULL == this)	//此判断是为了避免 空指针 的调用
		{
			return ;
		}
		ID = 12222;
		cout << "this is name for NULL_P test!!" << endl;
	}
	int ID;
};


//如果有属性在堆区开辟了空间，一定要自己创建  拷贝构造函数  ，防止浅拷贝带来的问题！！！！！！
//如果有属性在堆区开辟了空间，一定要自己创建  拷贝构造函数  ，防止浅拷贝带来的问题！！！！！！
//如果有属性在堆区开辟了空间，一定要自己创建  拷贝构造函数  ，防止浅拷贝带来的问题！！！！！！
 class student
{
public:
	student()
	{
		cout << "student 的 无参 构造函数！！！" << endl;
	}

	student(int age,int num,int id):s_age(age),s_num(new int(num)),s_ID(id)//这里无法给静态成员变量赋初始值
	{
		//s_age = age;
		//s_num = new int(num);
		//ID = id;
		cout << "有参  s_ID.ID=" << s_ID.ID << endl;
		cout << "student 的 有参 构造函数！！！" << endl;
	}

	student(const student& st)
	{
		//浅拷贝在简单的赋值操作中，会把多个对象的指针指向 被拷贝对象指针 指向的地址，所以在析构的时候，先 析构的对象，会把 被拷贝对象指针 指向的地址给释放了，导致被拷贝对象无法释放
		//简单来讲，浅拷贝有可能带来堆区内存的重复释放
		s_age = st.s_age;
		s_num = new int(*st.s_num);//注意，这里的 st.s_num 需要解引用（加 * ）
		s_ID.ID= ((st.s_ID).ID);
		height = st.height;
		cout << "拷贝   s_ID.ID=" << s_ID.ID << endl;
		cout << "student 的 拷贝 构造函数！！！" << endl;
	}

	~student()
	{
		if (s_num != NULL)//析构代码，把在堆区开辟的数据释放
		{
			delete s_num;
			s_num = NULL;
		}
		cout << "student 的析构函数！！！" << endl;
	}

	static void test11()//静态成员函数,通过  对象/类名 访问。
	{					//如果声明在私有作用域，那么类外不能访问。
		height = 199;
		cout << "static void test11:" << height << endl;
		//cout << "static void test11:" << s_age << endl; //静态成员函数 无法访问 非静态成员变量
	}


	student& add_age(student &st)//返回值是本体（对象），要用引用作为返回
	{							//add前不加引用，那就是返回一个值，等于创建了一个调用这个函数的对象的副本（假如是st2调用，那么就创建了一个新的对象=》st2_副本，拷贝构造创建的副本，然后这个副本在持续做加法操作，如果这个副本还在调用add，那么这个副本还会创建新的 副副本 ，由  副副本 持续加。)
		this->s_age += st.s_age;
		return *this;
	}
	void set_age(int s_age)
	{		//this可以解决名称重复产生的冲突
		s_age = s_age;//如果形参和成员变量同名，这样的赋值操作实际是“形参=形参”
		this->s_age = s_age;//  这样赋值才是将形参给到了成员变量
	}


	int s_age;
	int* s_num;
	stu_ID s_ID;//对象成员，先使用对象成员的构造，后使用本类的构造；先析构本类，再。。。
	int static  height;	//静态成员变量,所有对象共享同一份数据，不属于某一个对象。通过  对象/类名 访问。
						//如果声明在私有作用域，那么类外不能访问。
						//必须是类内声明，类外初始化
};

 int student::height = 144;

 class NULL_test {
	 //空对象安装用内存1 byte（字节），内存的基本单元为字节
	 //之所以会为空对象分配 1 byte，是为了区分 空对象 占内存的位置
	 //每个空对象都有一个独一无二的位置
	 //int aaa;					//这样有一个 非静态成员变量，就是4，注意字节对齐！！！。 属于类对象上
	 
	 //static int bbb			//有静态成员变量并不会增加对象所占内存的大小，因为不属于类对象上
	 //int test12(){}			//非静态成员函数   不属于类对象上
	 //static int test12(){}	//静态成员函数   不属于类对象上
	 //成员变量和成员函数会分开储存
 };

void test10(void)
{
	student st1(12, 14,1);
	student st2(st1);

	cout << "st1.height" << st1.height <<  endl;	//通过  对象 访问 静态成员变量
	st2.height = 187;//st1创建的时候height=144，st2拷贝过去的时候也是144，等到现在修改后是187，而st1和st2共享同一份数据，所以接下来打印的也是187.
	cout << "st1.height" << st1.height << endl;
	cout << "student::height" << student::height << endl;//通过  类名 访问 静态成员变量

	student::test11();

	NULL_test null_test;
	cout << "计算一个空的对象的大小（byte）：" << sizeof(null_test) << endl;

	cout << "st1的年龄" << st1.s_age << "  st1的号码" <<* st1.s_num << endl;
	cout << "st2的年龄" << st2.s_age << "  st2的号码" <<* st2.s_num << endl;

	st2.set_age(11);
	st2.add_age(st1).add_age(st1).add_age(st1).add_age(st1);//链式编程思想，和 cout<< 一样
	cout << "st2 age:" << st2.s_age<<endl;
	cout << "st1 age:" << st1.s_age << endl;


	stu_ID * p_test = NULL;
	p_test->show_name();// 空指针可以调用不涉及类成员的函数
	p_test->show_ID();//空指针可以调用涉及类成员的函数会报错！！！！！
}