#include "Allocator.hpp"

// 通过__TRACE_DEBUG做白盒测试

// 测试内存池的一级、二级配置器功能
void Test1()
{
	// 测试调用一级配置器分配内存
	cout << "测试调用一级配置器分配内存" << endl;
	char*p1 = SimpleAlloc<char, Alloc>::Allocate(129);
	SimpleAlloc<char, Alloc>::Deallocate(p1, 129);

	// 测试调用二级配置器分配内存
	cout << "测试调用二级配置器分配内存" << endl;
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
		printf("测试第%d次分配\n", i + 1);
		char*p = SimpleAlloc<char, Alloc>::Allocate(128);
	}
}

// 测试特殊场景
void Test2()
{
	cout << "测试内存池空间不足分配20个" << endl;
	// 8*20->8*2->320 
	char*p1 = SimpleAlloc<char, Alloc>::Allocate(8);

	char*p2 = SimpleAlloc<char, Alloc>::Allocate(8);

	cout << "测试内存池空间不足，系统堆进行分配" << endl;
	char*p3 = SimpleAlloc<char, Alloc>::Allocate(12);
}

// 测试系统堆内存耗尽的场景
void Test3()
{
	cout << "测试系统堆内存耗尽" << endl;

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