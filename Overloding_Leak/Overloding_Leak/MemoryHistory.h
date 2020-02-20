#pragma once
#include<Windows.h>
#include<time.h>
#include<stdio.h>
#include<iostream>
using namespace std;

class CMemoryHistory
{
public:
	enum
	{
		FILE_NAME_LEN = 128,
		ALLOC_INFO_MAX = 10
	};

	struct stALLOC_INFO
	{
		void* pAlloc;
		int iSize;
		char szFile[FILE_NAME_LEN];
		int iLine;
		bool bArray;
		bool bFree;
	};

private:
	stALLOC_INFO	_allocinfos[ALLOC_INFO_MAX];
	char						_logFileName[64];

public:
	CMemoryHistory(const char* szLogFile = "AllocInfo");
	~CMemoryHistory();

private:
	bool SaveLogFile();
	bool NewAlloc(void* ptr, const char* szFile, int iLine, int iSize, bool bArray = false);
	bool Delete(void* ptr, bool bArray = false); 


	friend void* operator new(size_t size, const char* File, int Line);
	friend void* operator new[](size_t size, const char* File, int Line);
	friend void  operator delete(void* p);
	friend void operator delete[](void* p);
};