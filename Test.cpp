#include "Allocator.hpp"

// ͨ��__TRACE_DEBUG���׺в���

// �����ڴ�ص�һ������������������
void Test1()
{
	// ���Ե���һ�������������ڴ�
	cout << "���Ե���һ�������������ڴ�" << endl;
	char*p1 = SimpleAlloc<char, Alloc>::Allocate(129);
	SimpleAlloc<char, Alloc>::Deallocate(p1, 129);

	// ���Ե��ö��������������ڴ�
	cout << "���Ե��ö��������������ڴ�" << endl;
	char*p2 = SimpleAlloc<char, Alloc>::Allocate(128);
	char*p3 = SimpleAlloc<char, Alloc>::Allocate(128);
	char*p4 = SimpleAlloc<char, Alloc>::Allocate(128);
	char*p5 = SimpleAlloc<char, Alloc>::Allocate(128);
	SimpleAlloc<char, Alloc>::Deallocate(p2, 128);
	SimpleAlloc<char, Alloc>::Deallocate(p3, 128);
	SimpleAlloc<char, Alloc>::Deallocate(p4, 128);
	SimpleAlloc<char, Alloc>::Deallocate(p5, 128);

	for (int i = 0; i < 21; ++i)
	{
		printf("���Ե�%d�η���\n", i + 1);
		char*p = SimpleAlloc<char, Alloc>::Allocate(128);
	}
}

// �������ⳡ��
void Test2()
{
	cout << "�����ڴ�ؿռ䲻�����20��" << endl;
	// 8*20->8*2->320 
	char*p1 = SimpleAlloc<char, Alloc>::Allocate(8);

	char*p2 = SimpleAlloc<char, Alloc>::Allocate(8);

	cout << "�����ڴ�ؿռ䲻�㣬ϵͳ�ѽ��з���" << endl;
	char*p3 = SimpleAlloc<char, Alloc>::Allocate(12);
}

// ����ϵͳ���ڴ�ľ��ĳ���
void Test3()
{
	cout << "����ϵͳ���ڴ�ľ�" << endl;

	SimpleAlloc<char, Alloc>::Allocate(1024 * 1024 * 1024);
	SimpleAlloc<char, Alloc>::Allocate(1024 * 1024);

	for (int i = 0; i < 100000; ++i)
	{
		char*p1 = SimpleAlloc<char, Alloc>::Allocate(128);
	}
}


int main()
{
	//Test1();
	//Test2();
	Test3();

	system("pause");
	return 0;
}