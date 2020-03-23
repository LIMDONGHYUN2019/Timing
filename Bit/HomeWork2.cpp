#define _crt_secure_no_warnings
#include <iostream>
#define endl '\n'

using namespace std;

int main()
{
	unsigned short Number = 0;
	int Tempo = 0;
	bool Flag;

	while (1)
	{
		cout << "Please Input in Position of Value(1 ~ 16) : ";
		cin >> Tempo;

		cout << Tempo << " Bit Value[1 / 0] : ";
		cin >> Flag;
		if (Flag)
		{
			Number = Number | (1 << (Tempo - 1));
		}
		else
		{
			if(Number & (1 << (Tempo - 1)))
				Number = Number ^ (1 << (Tempo - 1));
		}

		system("cls");

		for (int i = 16; i > 0; i--)
		{
			cout << i << "\tbit [On / Off] : ";
			if (Number & (1 << (i - 1)))
				cout << "On" << endl;
			else
				cout << "Off" << endl;
		}

		cout << endl;
	}
}