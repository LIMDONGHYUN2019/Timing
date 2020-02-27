#include<iostream>
#include<tchar.h>
#include<windows.h>


using namespace std;

int main()
{
	SYSTEM_INFO si;
	DWORD allocgranularity;
	DWORD pagesize;

	GetSystemInfo(&si);
	pagesize = si.dwPageSize;
	allocgranularity = si.dwAllocationGranularity;

	cout << pagesize / 1024 << endl;
	cout << allocgranularity / 1024 << endl;
}