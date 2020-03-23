#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<math.h>
#include<Windows.h>

#define dfSCREEN_WIDTH	71
#define dfSCREEN_HEIGHT	20
#define endl '\n'

using namespace std;

HANDLE WScreen[2]; 
char MainBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH] = {0,};
int Index = 0;


void cs_Initial()
{
	WScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	WScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO stConsoleCursor;
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(WScreen[0], &stConsoleCursor);
	SetConsoleCursorInfo(WScreen[1], &stConsoleCursor);
}

void cs_MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	SetConsoleCursorPosition(WScreen[Index], stCoord);
}

void cs_ClearScreen()
{
	DWORD dw; // unsigned long 
	for (short i = 0; i < dfSCREEN_HEIGHT; i++)
	{
		FillConsoleOutputCharacter(WScreen[Index], ' ', dfSCREEN_WIDTH - 1, { 0, i }, &dw);
	}
}

void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(WScreen[Index]);
	Index = !Index;
}

void DrawBuffer()
{
	DWORD dw;
	int Iy = 0;

	while (Iy < dfSCREEN_HEIGHT)
	{
		cs_MoveCursor(0, Iy);
		WriteFile(WScreen[Index], MainBuffer[Iy], dfSCREEN_WIDTH - 1, &dw, NULL);
		Iy++;
	}
}

void ScreenRelease()
{
	CloseHandle(WScreen[0]);
	CloseHandle(WScreen[1]);
}

void InitBuffer()
{
	for (int y = 0; y < dfSCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < dfSCREEN_WIDTH - 1; x++)
		{
			MainBuffer[y][x] = ' ';
		}
		MainBuffer[y][dfSCREEN_WIDTH - 1] = '\0';
	}
}

void DoubleBuffer_Sign(int& i)
{
	int iY = 0;
	while (iY < dfSCREEN_HEIGHT)
	{
		int iX = 0;
		double temp, j;
		temp = sin((i * (3.14 / 180)));

		for (j = -10; j < temp * 10; j++)
		{
			MainBuffer[iY][iX] = '*';
			iX++;
		}
		for(int k = iX; k < dfSCREEN_WIDTH; k++)
			MainBuffer[iY][k] = ' ';


		iY++;
		i += 15;
		if (i == 360)
			i = 0;
	}
}

void Function_Sign()
{
	int iX = 0;
	int iY = 0;
	int i = 0;
	double temp, j;

	while (1)
	{
		temp = sin((i * (3.14 / 180)));

		//printf("sin(%3d) = %+.2lf", i, temp);

		for (j = -10; j < (int)(temp * 10); j++)
		{
			printf("*");
		}

		printf("\n");
		i += 15;
		if (i == 360)
			i = 0;

		Sleep(33);
	}
}

void Run()
{
	int i = 0;
	while (1)
	{
		cs_ClearScreen();
		DrawBuffer();
		ScreenFlipping();
		DoubleBuffer_Sign(i);
		//================================================
		Sleep(95);
		i += 15;
	}
}


 
int main()
{
	//1¹ø
/*	system(" mode  con lines=20   cols=72 ");
	InitBuffer();
	cs_Initial();
	Run();*/	

	//2¹ø
	Function_Sign();
}
