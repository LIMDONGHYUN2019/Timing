#include"MemoryHistory.h"

CMemoryHistory g_MemoryHistory;

//void* operator new(size_t size)
//{
//	void* p = malloc(size);
//
//	cout << ":메모리 할당...." << endl;
//	return p;
//} // 기본적인 new 의 구조..

void* operator new(size_t size,const  char* File, int Line)
{
	void* p = malloc(size);
	g_MemoryHistory.NewAlloc(p, File, Line, size, true);

	return p;
}

void* operator new[](size_t size,const char* File, int Line)
{
	void* p = malloc(size);

	g_MemoryHistory.NewAlloc(p, File, Line, size, true);
	return p;
}

void operator delete(void* p)
{
	if (g_MemoryHistory.Delete(p))
		free(p);
}

void operator delete[](void* p)
{
	if (g_MemoryHistory.Delete(p, true))
		free(p);
}

#define new new(__FILE__, __LINE__) 

class Base
{
public:
	Base()
	{
		cout << "Base 생성자 성공....." << endl;
	}

	int _a;
	int _b;
	int _c;
};

class Sub : public Base
{
public:
	Sub()
	{
		cout << "Sub 생성자 성공...." << endl;
	}
};

int main()
{
	Sub* pa1 = new Sub[10];
	Sub* pa2 = new Sub;
	Sub* pa3 = new Sub[20];


	delete pa2;
	delete[] pa1;
	delete[] pa3;

	return 0;
}
