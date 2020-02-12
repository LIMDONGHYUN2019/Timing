//#pragma once
//#include<iostream>
//#include<Windows.h>
//#define Alloc_Max 100
//using namespace std;
//
//
//struct ALLOC_INFO
//{
//	void* ptr;
//	int Size;
//	char szFile[256];
//	int iLine;
//};
//
//ALLOC_INFO _Alloc_info[Alloc_Max];
//int iTotalAllocCount = 0;
//int iTotalAllocSize = 0;
//
//bool SaveAllocinfo(void *ptr, int iSize,const  char*szFile, int iLine)
//{
//	int icount;
//
//	for (icount = 0; icount < Alloc_Max; icount++)
//	{
//		if (_Alloc_info[icount].ptr == nullptr)
//		{
//			_Alloc_info[icount].ptr = ptr;
//			_Alloc_info[icount].Size = iSize;
//			_Alloc_info[icount].iLine = iLine;
//			strcpy_s(_Alloc_info[icount].szFile, sizeof(_Alloc_info[icount].szFile), szFile);
//
//			return true;
//		}
//	}
//
//	return false;
//}// 메모리 정보 배열에서 빈칸을 찾아서 정보를 넣는다.
//
//int FindAllocInfo(void *ptr)
//{
//	int icount;
//
//	if (ptr == nullptr)
//	{
//		return -1;
//	}
//
//	for (icount = 0; icount < Alloc_Max; icount++)
//	{
//		if (_Alloc_info[icount].ptr == ptr)
//		{
//			return icount;
//		}
//	}
//
//	return -1;
//}// 메모리 정보 배열에서 입력된 포인터의 정보를 찾는다.
//
//template<typename T>
//T* MemoryAlloc(int count ,  const char *szFile , int iLine)
//{
//	T* pNew = new T[count];
//
//	SaveAllocinfo(pNew, sizeof(T) * count, szFile, iLine);
//
//	iTotalAllocCount += 1;
//	iTotalAllocSize += sizeof(T) * count;
//
//	return pNew;
//}
//
//template<typename T>
//bool MemoryRelease(T* ptr)
//{
//	int Allocindex = FindAllocInfo(ptr);
//
//	if (Allocindex == -1)
//		return false;
//
//	memset(&_Alloc_info[Allocindex], 0, sizeof(ALLOC_INFO));
//
//	delete[] ptr;
//
//	return true;
//}
//
//bool PrintAlloc()
//{
//	cout << endl << "Total Alloc Size  :  " << iTotalAllocSize << endl << "Total Alloc Count   :   " << iTotalAllocCount << endl;
//
//	//해제된 메모리 출력.
//
//	int icount;
//	for (icount = 0; icount < Alloc_Max; icount++)
//	{
//		if (_Alloc_info[icount].ptr != nullptr)
//		{
//			cout << "Not Release Memory  :  [0x" << _Alloc_info[icount].ptr << "]   " << _Alloc_info[icount].Size << "Bytes" << endl;
//			cout << "File  :  " << _Alloc_info[icount].szFile << "  :  " << _Alloc_info[icount].iLine << endl;
//		}
//	}
//
//	return true;
//}
//
//
//
//int main()
//{
//	memset(_Alloc_info, 0, sizeof(ALLOC_INFO) * Alloc_Max);
//	//초기화용도로 nullptr값으로 포맷...
//
//	//int* p = MemoryAlloc<int>(1, __FILE__, __LINE__);
//	#define _MemoryAlloc(T, Size)	MemoryAlloc<T>(Size, __FILE__, __LINE__);
//	
//	int* p4 = _MemoryAlloc(int, 1);
//	int* p5 = _MemoryAlloc(int, 100);
//	
//
//	char* c4 = _MemoryAlloc(char, 50);
//	char* c5 = _MemoryAlloc(char, 500);
//	MemoryRelease(p4);
//	MemoryRelease(c4);
//
//	PrintAlloc();
//
//	return 0;   
//}


