#include"func.h"

//��Ԫ��Ŀ�������� ���� ���� �� ���Է�����һ����Home��˽�г�Ա��

//�ڱ�д��ʱ��ע�⣬�����ʵ��ࣨHome����Ҫ����������֮ǰ������������֮��ʵ�֡�
//������ĺ���ʵ����Ҫ�� �������� ʵ��֮�� ʵ�֣�Ҳ����˵��������ĺ���������������д������ ��������ʵ�� �ĺ���
class Home;

class Building {
public:
	Building();
	Home *home;//�����г����������ָ��ʱ����ʼ����ʱ����Ҫ��Ϊ�������������һ��ռ䣬�����ʼ������ָ����ָ�����ռ�

	void visit();
private:

};

class BB {
public:
	BB();
	Home* home;//�����г����������ָ��ʱ����ʼ����ʱ����Ҫ��Ϊ�������������һ��ռ䣬�����ʼ������ָ����ָ�����ռ�

	void visit1();

	void putong_visit();
private:

};

class Home {
	friend void GoodFriend(Home* fri);	//����  ȫ����Ԫ����
	friend class Building;				//����  ��Ԫ��
	friend void BB::visit1();			//����  ��Ԫ ��Ա����..���߱�������BB���еĳ�Ա���� visit1 ��Ϊ ���� ����Ԫ����
public:
	string H_dating = "����";

private:
	string H_bedroom = "����";


};

Building::Building() { home = new Home; }

void GoodFriend(Home *fri)//ȫ����Ԫ����
{
	cout << "�����ѽ���" << fri->H_dating << endl;
	cout << "�����ѽ���" << fri->H_bedroom << endl;

}

BB::BB() { home = new Home; }
void BB::visit1()
{
	cout << "�����ѽ���" << home->H_dating << endl;
	cout << "�����ѽ���" << home->H_bedroom << endl;
}

void BB::putong_visit()
{
	cout << "�����ѽ���" << home->H_dating << endl;
	//cout << "�����ѽ���" << home->H_bedroom << endl;
}
void Building::visit()
{
	cout << "�����ѽ���" << home->H_dating << endl;
	cout << "�����ѽ���" << home->H_bedroom << endl;
}


void test14()
{
	cout << "test14 start!!!!!!!!" << endl;
	cout << "��Ԫ ȫ�ֺ���" << endl;
	Home h1;
	GoodFriend(&h1);
}

void test15()
{
	cout << "test15 start!!!!!!!!" << endl;
	cout << "��Ԫ �� " << endl;
	Building b1;
	
	b1.visit();
	delete b1.home;
}

void test16()
{
	cout << "test16 start!!!!!!!!" << endl;
	cout << "��Ԫ ��Ա����  " << endl;
	BB b1;
	b1.visit1();
}