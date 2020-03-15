#include<iostream>
using namespace std;

void _Strcat(char* ps1, char* ps2);
void my_strcat(char* pA, char* pB);
int _Strlen(char* ps);

int main()
{
	char str2[9] = "Power";
	char str[20] = "Over ";


	my_strcat(str, str2);

	printf("%s\n", str);
}

void _Strcat(char* ps1, char* ps2)
{
	int Count = 0;
	int Pos = _Strlen(ps1);

	while (ps2[Count])
	{
		ps1[Pos + Count] = ps2[Count];
		Count++;
	}
	ps1[Pos + Count] = '\0';
}

int _Strlen(char* ps)
{
	int Count = 0;
	while (ps[Count])
		Count++;
	return Count;
}

void my_strcat(char* pA, char* pB)
{
	while (*pA) //일단 '\0' 까지 간다!
	{
		*pA++;
	}

	while (*pA = *pB)
	{
		*pA++;
		*pB++;
	}
}
