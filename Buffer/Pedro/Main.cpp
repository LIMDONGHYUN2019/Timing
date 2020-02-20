#include<iostream>
#include<Windows.h>
#define dfSCREEN_WIDTH		71
#define dfSCREEN_HEIGHT	20
using namespace std;


//HANDLE WScreen[2]; 
//char MainBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH] = {0,};
//int Index = 0;
//void cs_Initial()
//{
//	WScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
//		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	WScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
//		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//
//	CONSOLE_CURSOR_INFO stConsoleCursor;
//	stConsoleCursor.bVisible = FALSE;
//	stConsoleCursor.dwSize = 1;
//	//SetConsoleCursorInfo(, &stConsoleCursor);
//	SetConsoleCursorInfo(WScreen[0], &stConsoleCursor);
//	SetConsoleCursorInfo(WScreen[1], &stConsoleCursor);
//}
//
//void cs_MoveCursor(int iPosX, int iPosY, int index)
//{
//	COORD stCoord;
//	stCoord.X = iPosX;
//	stCoord.Y = iPosY;
//	SetConsoleCursorPosition(WScreen[index], stCoord);
//}
//
//void cs_ClearScreen(int index)
//{
//	DWORD dw; // unsigned long 
//	for (short i = 0; i < dfSCREEN_HEIGHT; i++)
//	{
//		FillConsoleOutputCharacter(WScreen[index], ' ', dfSCREEN_WIDTH - 1, { 0, i }, &dw);
//	}
//}
//
//void ScreenFlipping()
//{
//	SetConsoleActiveScreenBuffer(WScreen[Index]);
//	Index = !Index;
//}
//
//void ScreenClear()
//{
//	cs_ClearScreen(Index);
//}
//
//void DrawBuffer()
//{
//	DWORD dw;
//	int Iy = 0;
//
//	while (Iy < dfSCREEN_HEIGHT)
//	{
//		cs_MoveCursor(0, Iy, Index);
//		WriteFile(WScreen[Index], MainBuffer[Iy], dfSCREEN_WIDTH - 1, &dw, NULL);
//		Iy++;
//	}
//}
//
//void ScreenRelease()
//{
//	CloseHandle(WScreen[0]);
//	CloseHandle(WScreen[1]);
//}
//
//void Run()
//{
//	while (1)
//	{
//		ScreenClear();
//
//		DrawBuffer();
//		ScreenFlipping();
//	}
//}


//============================================================
//이둘의 가장큰 차이점은  버퍼를 2개를 사용하나 1개를 사용하나 차이인데
//2개를 사용하는것이 더블버퍼링인데 가장 안정적이고 좋다...
//그리고 1개를 사용하면 깜빡임은 결국 생기게되어있다.
//하나만사용할떄에는 버퍼를 생성하기보단 STD_OUTPUT_HANDLE을통해 핸들값으로 사용한다.


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//이것은 그저 출력화면 핸들값을 가져오는것이지..... 화면버퍼라는것을 가지고오는것은 아니다.
char MainBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];
int Index = 0;
void cs_Initial()
{

	CONSOLE_CURSOR_INFO stConsoleCursor;
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);
}

void cs_MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	SetConsoleCursorPosition(hConsole, stCoord);
}

void cs_ClearScreen()
{
	DWORD dw; // unsigned long 
	for (short i = 0; i < dfSCREEN_HEIGHT; i++)
	{
		FillConsoleOutputCharacter(hConsole, ' ', dfSCREEN_WIDTH - 1, { 0, i }, &dw);
	}
}

void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(hConsole);
}

void ScreenClear()
{ 
	cs_ClearScreen();
}

void DrawBuffer()
{
	DWORD dw;
	int Iy = 0;

	while (Iy < dfSCREEN_HEIGHT)
	{
		cs_MoveCursor(0, Iy);
		WriteFile(hConsole, MainBuffer[Iy], dfSCREEN_WIDTH - 1, &dw, NULL);
		//cout << MainBuffer[Iy];
		cout << 3;
		Iy++;
	}
}

void ScreenRelease()
{

}

void Run()
{
	while (1)
	{
		ScreenClear();
		DrawBuffer();
		//ScreenFlipping();
		Sleep(33); 
	}
}



int main()
{
	system(" mode  con lines=20   cols=72 ");
	for (int y = 0; y < dfSCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < dfSCREEN_WIDTH - 1; x++)
		{
			MainBuffer[y][x] = ' ';
		}
		MainBuffer[y][dfSCREEN_WIDTH - 1] = '\0';
	}

	MainBuffer[19][40] = 'M';//시작위치

	cs_Initial();

	Run();

}
