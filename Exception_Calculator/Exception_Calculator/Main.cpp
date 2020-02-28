#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include<tchar.h>

using namespace std;

enum { DIV = 1, MUL, ADD, MIN, EXIT };

DWORD ShowMenu();
BOOL Calculator();

int main()
{
	BOOL state;

	do
	{
		state = Calculator();
	} while (state == TRUE);

	return 0;
}

BOOL Calculator()
{
	DWORD sel;
	int num1, num2, result;

	sel = ShowMenu();

	if (sel == EXIT)
	{
		cout << "Game Over now !!!!" << endl;
		return FALSE;
	}

	_fputts(_T("Input num1, num2  ="), stdout);
	_tscanf(_T("%d %d"), &num1, &num2);

	__try
	{
		switch (sel)
		{
		case DIV:
			result = num1 / num2;
			_tprintf(_T("%d / %d = %d \n"), num1, num2, result);
			break;

		case MUL:
			result = num1 * num2;
			_tprintf(_T("%d * %d = %d \n"), num1, num2, result);
			break;

		case ADD:
			result = num1 + num2;
			_tprintf(_T("%d + %d = %d \n"), num1, num2, result);
			break;

		case MIN:
			result = num1 - num2;
			_tprintf(_T("%d - %d = %d  \n"), num1, num2, result);
			break;
		}
	}

	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		_tprintf(_T("Wrong number inserted Maybe.... Try again now !! \n"));
	}

	return TRUE;
}