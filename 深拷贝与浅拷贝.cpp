#include"func.h"


class stu_ID
{
public:
	stu_ID() {}
	stu_ID(int id)
	{
		ID = id;
		cout << "ID�ǣ�"<<id<<" �Ѿ�������" << endl;
	}
	void show_name()
	{
		cout << "this is name for NULL_P test!!" << endl;
	}
	void show_ID()
	{
		if (NULL == this)	//���ж���Ϊ�˱��� ��ָ�� �ĵ���
		{
			return ;
		}
		ID = 12222;
		cout << "this is name for NULL_P test!!" << endl;
	}
	int ID;
};


//����������ڶ��������˿ռ䣬һ��Ҫ�Լ�����  �������캯��  ����ֹǳ�������������⣡����������
//����������ڶ��������˿ռ䣬һ��Ҫ�Լ�����  �������캯��  ����ֹǳ�������������⣡����������
//����������ڶ��������˿ռ䣬һ��Ҫ�Լ�����  �������캯��  ����ֹǳ�������������⣡����������
 class student
{
public:
	student()
	{
		cout << "student �� �޲� ���캯��������" << endl;
	}

	student(int age,int num,int id):s_age(age),s_num(new int(num)),s_ID(id)//�����޷�����̬��Ա��������ʼֵ
	{
		//s_age = age;
		//s_num = new int(num);
		//ID = id;
		cout << "�в�  s_ID.ID=" << s_ID.ID << endl;
		cout << "student �� �в� ���캯��������" << endl;
	}

	student(const student& st)
	{
		//ǳ�����ڼ򵥵ĸ�ֵ�����У���Ѷ�������ָ��ָ�� ����������ָ�� ָ��ĵ�ַ��������������ʱ���� �����Ķ��󣬻�� ����������ָ�� ָ��ĵ�ַ���ͷ��ˣ����±����������޷��ͷ�
		//��������ǳ�����п��ܴ��������ڴ���ظ��ͷ�
		s_age = st.s_age;
		s_num = new int(*st.s_num);//ע�⣬����� st.s_num ��Ҫ�����ã��� * ��
		s_ID.ID= ((st.s_ID).ID);
		height = st.height;
		cout << "����   s_ID.ID=" << s_ID.ID << endl;
		cout << "student �� ���� ���캯��������" << endl;
	}

	~student()
	{
		if (s_num != NULL)//�������룬���ڶ������ٵ������ͷ�
		{
			delete s_num;
			s_num = NULL;
		}
		cout << "student ����������������" << endl;
	}

	static void test11()//��̬��Ա����,ͨ��  ����/���� ���ʡ�
	{					//���������˽����������ô���ⲻ�ܷ��ʡ�
		height = 199;
		cout << "static void test11:" << height << endl;
		//cout << "static void test11:" << s_age << endl; //��̬��Ա���� �޷����� �Ǿ�̬��Ա����
	}


	student& add_age(student &st)//����ֵ�Ǳ��壨���󣩣�Ҫ��������Ϊ����
	{							//addǰ�������ã��Ǿ��Ƿ���һ��ֵ�����ڴ�����һ��������������Ķ���ĸ�����������st2���ã���ô�ʹ�����һ���µĶ���=��st2_�������������촴���ĸ�����Ȼ����������ڳ������ӷ��������������������ڵ���add����ô����������ᴴ���µ� ������ ����  ������ �����ӡ�)
		this->s_age += st.s_age;
		return *this;
	}
	void set_age(int s_age)
	{		//this���Խ�������ظ������ĳ�ͻ
		s_age = s_age;//����βκͳ�Ա����ͬ���������ĸ�ֵ����ʵ���ǡ��β�=�βΡ�
		this->s_age = s_age;//  ������ֵ���ǽ��βθ����˳�Ա����
	}


	int s_age;
	int* s_num;
	stu_ID s_ID;//�����Ա����ʹ�ö����Ա�Ĺ��죬��ʹ�ñ���Ĺ��죻���������࣬�١�����
	int static  height;	//��̬��Ա����,���ж�����ͬһ�����ݣ�������ĳһ������ͨ��  ����/���� ���ʡ�
						//���������˽����������ô���ⲻ�ܷ��ʡ�
						//���������������������ʼ��
};

 int student::height = 144;

 class NULL_test {
	 //�ն���װ���ڴ�1 byte���ֽڣ����ڴ�Ļ�����ԪΪ�ֽ�
	 //֮���Ի�Ϊ�ն������ 1 byte����Ϊ������ �ն��� ռ�ڴ��λ��
	 //ÿ���ն�����һ����һ�޶���λ��
	 //int aaa;					//������һ�� �Ǿ�̬��Ա����������4��ע���ֽڶ��룡������ �����������
	 
	 //static int bbb			//�о�̬��Ա�������������Ӷ�����ռ�ڴ�Ĵ�С����Ϊ�������������
	 //int test12(){}			//�Ǿ�̬��Ա����   �������������
	 //static int test12(){}	//��̬��Ա����   �������������
	 //��Ա�����ͳ�Ա������ֿ�����
 };

void test10(void)
{
	student st1(12, 14,1);
	student st2(st1);

	cout << "st1.height" << st1.height <<  endl;	//ͨ��  ���� ���� ��̬��Ա����
	st2.height = 187;//st1������ʱ��height=144��st2������ȥ��ʱ��Ҳ��144���ȵ������޸ĺ���187����st1��st2����ͬһ�����ݣ����Խ�������ӡ��Ҳ��187.
	cout << "st1.height" << st1.height << endl;
	cout << "student::height" << student::height << endl;//ͨ��  ���� ���� ��̬��Ա����

	student::test11();

	NULL_test null_test;
	cout << "����һ���յĶ���Ĵ�С��byte����" << sizeof(null_test) << endl;

	cout << "st1������" << st1.s_age << "  st1�ĺ���" <<* st1.s_num << endl;
	cout << "st2������" << st2.s_age << "  st2�ĺ���" <<* st2.s_num << endl;

	st2.set_age(11);
	st2.add_age(st1).add_age(st1).add_age(st1).add_age(st1);//��ʽ���˼�룬�� cout<< һ��
	cout << "st2 age:" << st2.s_age<<endl;
	cout << "st1 age:" << st1.s_age << endl;


	stu_ID * p_test = NULL;
	p_test->show_name();// ��ָ����Ե��ò��漰���Ա�ĺ���
	p_test->show_ID();//��ָ����Ե����漰���Ա�ĺ����ᱨ����������
}