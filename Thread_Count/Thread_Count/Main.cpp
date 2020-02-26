#include<iostream>
#include<stdio.h>
#include<tchar.h>
#include<Windows.h>

#define Max_Thread (1024 * 10)

using	namespace std;


DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	DWORD threadnum = (DWORD)lpParam;

	while (1)
	{
		_tprintf(_T("thread num : %d \n"), threadnum);
		Sleep(5000);
	}

	return 0;
}

DWORD countThread = 0;

int main()
{
	DWORD dwThreadID[Max_Thread];
	HANDLE hThread[Max_Thread];

	while (1)
	{
		hThread[countThread] = CreateThread(
			NULL, 1024 * 1024 * 0.5, ThreadProc, (LPVOID)countThread,
			0, &dwThreadID[countThread]
		);

		if (hThread[countThread] == NULL)
		{
			_tprintf(_T("MAXIMUM THREAD NUMBER:    %d\n"), countThread);

			break;
		}
		countThread++;
	}

	for (DWORD i = 0; i < countThread; i++)
	{
		CloseHandle(hThread[i]);
	}

	return 0;
}