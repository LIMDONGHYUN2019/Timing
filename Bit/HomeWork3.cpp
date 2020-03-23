#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define endl '\n'

using namespace std;

int main()
{
	unsigned int Main = 0;
	unsigned int Pos;
	unsigned int Value;
	
	while (1)
	{
		unsigned int lnit = 255;

		cout << "Position (1 ~ 4)  :";     
		scanf("%d", &Pos);
		cout << "Input Value[0 ~ 255] : ";
		scanf("%d", &Value);
		system("cls");

		lnit = ~(lnit << ((Pos - 1) * 8));
		Main = Main & lnit;

		Value = Value << ((Pos - 1) * 8);
		Main = Main | Value;

		for (int i = 0; i < 4; i++)
		{
			lnit = 255;
			lnit = (lnit << (i * 8));
			lnit = ((Main & lnit) >> (i * 8));

			cout << i + 1 << " Pos Value : ";
			printf("%d\n", lnit);
		}
		printf("¡æ 0x%p\n", Main);
	}

}