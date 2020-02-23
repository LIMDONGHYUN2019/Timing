#include<iostream>
#include"Console.h"
#include<Windows.h>
#include<conio.h>
using namespace std;

#ifdef _DEBUG
#define	new	new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif 


class Base
{
public:
	Base():
		_iX(0)
	{
	}
	~Base()
	{
	}
protected:
	int _iX; 
	
public:
	virtual bool Run(int iY) = 0;
	virtual void Render(int iY) = 0;

	int Get_iX()
	{
		return _iX;
	}
};
//=========================
class OneStar : public Base
{
public:
	bool Run(int iY)
	{
		MainBuffer[iY][_iX] = ' ';
		if (_iX + 1 >= dfSCREEN_WIDTH - 1)
		{
			return false;
		}

		_iX += 1;
		return true;
	}
	void Render(int iY)
	{
		MainBuffer[iY][_iX] = 'O';
	}
};
class TwoStar : public Base
{
public:
	bool Run(int iY)
	{
		MainBuffer[iY][_iX] = ' ';
		MainBuffer[iY][_iX + 1] = ' ';
		if (_iX + 2>= dfSCREEN_WIDTH - 1)
		{
			return false;
		}

		_iX += 2;
		return true;
	}
	void Render(int iY)
	{

		MainBuffer[iY][_iX] = 'O';
		MainBuffer[iY][_iX + 1] = 'O';
	}
};

class ThreeStar : public Base
{
public:
	bool Run(int iY)
	{
		MainBuffer[iY][_iX] = ' ';
		MainBuffer[iY][_iX + 1] = ' ';
		MainBuffer[iY][_iX + 2] = ' ';
		if (_iX + 3 >= dfSCREEN_WIDTH - 1)
		{
			return false;
		}

		_iX += 3;
		return true;
	}
	void Render(int iY)
	{
		MainBuffer[iY][_iX] = 'O';
		MainBuffer[iY][_iX + 1] = 'O';
		MainBuffer[iY][_iX + 2] = 'O';
	}
};

Base* Star[Arr_Size] = { 0, };
int Exit = 0;


void KeyProcess()
{
	int i;
	for (i = 0; i < Arr_Size; i++)
	{
		if (Star[i] == nullptr)
		{
			break;
		}
	}

	if (i > Arr_Size - 1)
	{
		return;
	}

	char Key;

	if (_kbhit())
	{
		Key = _getch();

		switch (Key)
		{
		case '1':
			if (Star[i] == nullptr)
			{
				Star[i] = new OneStar;
			}
			break;
		case '2':
			if (Star[i] == nullptr)
			{
				Star[i] = new TwoStar;
			}
			break;
		case '3':
			if (Star[i] == nullptr)
			{
				Star[i] = new ThreeStar;
			}
			break;
		case 6:
			Exit = 1;
			break; 
		default:
			break;
		}
	}
}

void Run()
{
	for (int i = 0; i < Arr_Size; i++)
	{
		if (Star[i] != nullptr)
		{
			if (!Star[i]->Run(i))
			{
				MainBuffer[i][Star[i]->Get_iX()] = ' ';
				delete Star[i];
				Star[i] = nullptr;
			}
		}
	}
}

void Render()
{
	for (int i = 0; i < Arr_Size; i++)
	{
		 if (Star[i] != nullptr)
		{
			Star[i]->Render(i);
		}

	}
}

void DrawBuffer()
{
	DWORD dw;
	int Iy = 0;

	while (Iy < dfSCREEN_HEIGHT)
	{
		cs_MoveCursor(0, Iy, Index);
		WriteFile(WScreen[Index], MainBuffer[Iy], dfSCREEN_WIDTH - 1, &dw, NULL);
		Iy++;
	}
}

void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(WScreen[Index]);
	Index = !Index;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	system(" mode  con lines=20   cols=75 ");
	cs_Initial();
	


	while (1)
	{
		cs_ClearScreen(Index);

		KeyProcess();
		Run();
		Render();

		DrawBuffer();
		ScreenFlipping();
		if (Exit)
			break;
		Sleep(33);
	}
}