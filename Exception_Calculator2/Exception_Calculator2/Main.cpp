#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include<tchar.h>

using namespace std;

DWORD ShowMenu();
BOOL Calculator();
DWORD FileterFunction(DWORD exptType);

enum { DIV = 1, MUL, ADD, MIN, EXIT };
int num1, num2, result;

int main()
{
	bool state = true;

	while (state == TRUE)
	{
		system("cls");
		state = Calculator();
		system("pause");
	}

	return 0;
}

DWORD ShowMenu()
{
	DWORD sei;

	_fputts(_T("-----Menu-----\n"), stdout);
	_fputts(_T("num 1 : Divide \n"), stdout);
	_fputts(_T("num 2 : Multiple \n"), stdout);
	_fputts(_T("num 3 : Add \n"), stdout);
	_fputts(_T("num 4 : Minus \n"), stdout);
	_fputts(_T("num 5 : Exit \n\n"), stdout);
	_fputts(_T("Select a Number now :  "), stdout);
	_tscanf(_T("%d"), &sei);

	return sei;
}

BOOL Calculator()
{
	DWORD sel;

	sel = ShowMenu();

	if (sel == EXIT)
	{
		cout << "Game Over now !!!!" << endl;
		return FALSE;
	}

	_fputts(_T("\nInput num1, num2  =  "), stdout);
	_tscanf(_T("%d %d"), &num1, &num2);
	cout << endl;

	__try
	{
		__try
		{
			switch (sel)
			{
			case DIV:
				result = num1 / num2;
				_tprintf(_T("Result -> %d / %d = %d \n"), num1, num2, result);
				break;

			case MUL:
				result = num1 * num2;
				_tprintf(_T("Result -> %d * %d = %d \n"), num1, num2, result);
				break;

			case ADD:
				result = num1 + num2;
				_tprintf(_T("Result -> %d + %d = %d \n"), num1, num2, result);
				break;

			case MIN:
				result = num1 - num2;
				_tprintf(_T("Result -> %d - %d = %d  \n"), num1, num2, result);
				break;
			}
		}
		__finally
		{
			_tprintf(_T("End Operating !!! \n\n"));
		}
	}

	__except (FileterFunction(GetExceptionCode()))
	{
		_tprintf(_T("Wrong number inserted Maybe.... Try again now !! \n\n"));
	}

	return TRUE;
}

DWORD FileterFunction(DWORD exptType)
{
	switch (exptType)
	{
	case EXCEPTION_ACCESS_VIOLATION:
		_tprintf(_T("Access Violation \n\n"));
		return EXCEPTION_EXECUTE_HANDLER;

	case EXCEPTION_INT_DIVIDE_BY_ZERO:
		_tprintf(_T("Wrong Number inserted.... \n"));
		_tprintf(_T("Input second number again  : "));
		_tscanf(_T("%d"), &num2);
		return EXCEPTION_CONTINUE_EXECUTION;

	default:
		return EXCEPTION_EXECUTE_HANDLER;
	}
}