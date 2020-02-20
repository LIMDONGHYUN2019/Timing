#include<iostream>
#include<Windows.h>
#define Alloc_Max 100
#define _MemoryAlloc(p, size)	Memory_Alloc<p>(size, __FILE__, __LINE__)
using namespace std;

struct Alloc_Info
{
	void* ptr;
	char szFileName[256];
	int iSize;
	int iLine;
	char Alloc_Type[30];
};
Alloc_Info _Alloc_info[Alloc_Max];
int iTotalAlloc_Size;
int iTotalAlloc_Count;

void Save_Alloc(void *ptr, int icount, int size, const char* filename, int line, const char* type)
{
	_Alloc_info[icount].ptr = ptr;
	_Alloc_info[icount].iSize = size;
	_Alloc_info[icount].iLine = line;
	strcpy_s(_Alloc_info[icount].szFileName, sizeof(_Alloc_info[icount].szFileName), filename);
	strcpy_s(_Alloc_info[icount].Alloc_Type, sizeof(_Alloc_info[icount].Alloc_Type), type);
}

template <typename T>
T* Memory_Alloc(int size, const char* filename, int line)
{
	int iCount;
	for (iCount = 0; iCount < Alloc_Max; iCount++)
	{
		if (_Alloc_info[iCount].ptr == nullptr)
		{
			T* pAlloc = new T[size];
			Save_Alloc(pAlloc, iCount, sizeof(T) * size, filename, line, typeid(T).name());
			iTotalAlloc_Size += sizeof(T) * size;
			iTotalAlloc_Count += 1;

			return pAlloc;
		}
	}

	return 0;
}

int Find_Alloc(void *ptr)
{
	int iCount;

	for (iCount = 0; iCount < Alloc_Max; iCount++)
	{
		if (_Alloc_info[iCount].ptr == ptr)
		{
			return iCount;
		}
	}

	return -1;
}

template <typename T>
bool Release_Alloc(T *ptr)
{
	int iCount = Find_Alloc(ptr);

	if (iCount == -1)
		return false;

	memset(&_Alloc_info[iCount], 0, sizeof(Alloc_Info));
	delete[] ptr;
	return true;
}

void Print_Alloc()
{

	int iCount;

	cout << "================================================" << endl;
	cout << "Total Alloc Size    :  " << iTotalAlloc_Size << endl;
	cout << "Total Alloc Count   :  " << iTotalAlloc_Count << " Count" << endl;
	cout << "================================================" << endl;

	for (iCount = 0; iCount < Alloc_Max; iCount++)
	{
		if (_Alloc_info[iCount].ptr != nullptr)
		{
			cout << endl;
			cout << "Alloc_Array  ¡æ   iCount :  " << iCount << endl;
			cout << "¡Ú¡Ú  No Release Alloc Information  ¡Ú¡Ú " << endl;
			cout << "Alloc File Name  :  " << '\t' << _Alloc_info[iCount].szFileName << endl;
			cout << "Alloc Address Value  :" << '\t' << _Alloc_info[iCount].ptr << endl;
			cout << "Alloc Line Value  :  " << '\t' << _Alloc_info[iCount].iLine << " Number" << endl;
			cout << "Alloc Size / Type  :  " << '\t' << _Alloc_info[iCount].iSize << " Size" << "   /   " << _Alloc_info[iCount].Alloc_Type << " Type" << endl;
			cout << "=================================================" << endl;
		}
	}

	cout << endl;
}

int main()
{
	memset(_Alloc_info, 0, sizeof(Alloc_Info) * Alloc_Max);

	int* p1 = _MemoryAlloc(int, 1);
	int* p2 = _MemoryAlloc(int, 400);
	char* c1 = _MemoryAlloc(char, 100);
	char* c2 = _MemoryAlloc(char, 700);

	short* s1 = _MemoryAlloc(short, 300);

	Release_Alloc(p1);
	Release_Alloc(c2);

	Print_Alloc();
}