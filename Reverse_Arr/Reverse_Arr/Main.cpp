#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#define endl '\n'
#define Arr_Size 100

using namespace std;


void Reverse(char *ptr)
{
	int size = strlen(ptr);
	for (int i = 0; i < size / 2; i++)
	{
		char temp = ptr[size - i - 1];
		ptr[size - i - 1] = ptr[i];
		ptr[i] = temp;
	}
}

int main()
{
	char MyArr[Arr_Size];
	gets_s(MyArr, 30);
	Reverse(MyArr);
	cout << "\n---Reverse On..!!---\n" << endl;
	cout << MyArr << endl;
}