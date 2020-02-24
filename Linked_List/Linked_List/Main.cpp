#include<iostream>
#include<Windows.h>
#include"Linked.h"

using namespace std;


int main()
{
	CList<int> list;

	for (int i = 1; i < 5; i++)
	{
		list.Push_Front(i);
	}

	CList<int> ::iterator iter;
	CList<int> ::iterator iterend = list.End();

	list.sort();

	for (iter = list.begin(); iter != iterend; iter++)
	{
		cout << *iter << endl;
	}

	cout << "===========" << endl;


	for (iter = list.begin(); iter != iterend; )
	{
		list.erase(iter);
	}

	cout << "중간점검...." << endl;


	iter = list.begin();
	if (!*iter)
	{
		cout << "데이터가 없네유...." << endl;
		cout << *iter << endl;
	}

}