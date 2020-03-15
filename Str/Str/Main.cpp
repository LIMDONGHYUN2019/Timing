#include<iostream>
#define endl '\n'
using namespace std;

int _strlen(const char* str)
{
	int a = 0;

	while (str[a])
		a++;

	return a;
}

void _strcpy(char* str1, const  char* str2)
{
	int Pos = 0;

	while (str1[Pos] = str2[Pos])
	{
		Pos++;
	}

}

int main()
{

	const char *Source = "Power and Show";

	char Trash[20];

	cout << _strlen(Source) << endl;
	
	_strcpy(Trash, Source);
	cout << "Source : " << Source << endl;

	cout << "Trash2 : " << Trash << endl;

}