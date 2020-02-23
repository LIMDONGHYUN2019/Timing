#pragma once
#include<iostream>
#include<windows.h>
#include<stdbool.h>
#include<vector>
#include<list>
#include<conio.h>
//#define _CRT_SECURE_NO_WARNINGS
#define dfSCREEN_WIDTH		70	// ÄÜ¼Ö °¡·Î 80Ä­ + NULL
#define dfSCREEN_HEIGHT	20	// ÄÜ¼Ö ¼¼·Î 24Ä­
#define Arr_Size 20

using namespace std;

HANDLE WScreen[2];
char MainBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH] = {0, };
int  Index = 0;


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


void cs_MoveCursor(int iPosX, int iPosY, int index)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	SetConsoleCursorPosition(WScreen[index], stCoord);
}


void cs_ClearScreen(int index)
{
	DWORD dw; // unsigned long 
	for (short i = 0; i < dfSCREEN_HEIGHT; i++)
	{
		cs_MoveCursor(0, i, index);
		FillConsoleOutputCharacter(WScreen[index], ' ', dfSCREEN_WIDTH - 1, { 0, i }, &dw);
	}
}




