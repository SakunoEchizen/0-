#include"func.h"

class CPU
{
public:
	virtual void calculator()=0;
};

class GPU
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class PC
{
public:

	virtual void doWork(CPU* c, GPU* g, Memory *m) {}
};


class amd_cpu :public CPU
{
public:
	void calculator()
	{
		cout << "AMD calculator!!!" << endl;
	}
};

class amd_gpu :public GPU
{
public:
	void display()
	{
		cout << "AMD display!!!" << endl;
	}
};

class amd_Memory :public Memory
{
public:
	void storage()
	{
		cout << "AMD storage!!!" << endl;
	}
};

class ASUS :public PC
{
public:

	void doWork(CPU* c, GPU* g, Memory *m)
	{
		cout << "PC ASUS is worked!!!" << endl;
		c->calculator();
		g->display();
		m->storage();
	}
};

void test34(void)
{
	cout << "\ntest 34 start!!!!!!!!\n" << endl;
	ASUS a1;
	CPU* cpu = new amd_cpu;
	GPU* gpu = new amd_gpu;
	Memory* memory = new amd_Memory;
	a1.doWork(cpu,gpu,memory);

}