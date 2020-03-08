#include<iostream>
#include<windows.h>

#define col 8
#define row 10
using namespace std;

const char* Star[col][row] = {
	{"¡Ù","¡à","¡Ù","¡Ù","¡Ù","¡Ù","¡Ù","¡à","¡à","¡à"},
	{"¡Ù","¡Ù","¡à","¡Ù","¡à","¡à","¡Ù","¡Ù","¡Ù","¡Ù"},
	{"¡Ù","¡Ù","¡Ù","¡Ù","¡à","¡Ù","¡à","¡Ù","¡à","¡Ù"},
	{"¡Ù","¡à","¡à","¡Ù","¡Ù","¡Ù","¡Ù","¡Ù","¡à","¡Ù"},
	{"¡Ù","¡Ù","¡Ù","¡Ù","¡à","¡Ù","¡à","¡Ù","¡Ù","¡à"},
	{"¡Ù","¡à","¡à","¡Ù","¡à","¡Ù","¡à","¡Ù","¡Ù","¡Ù"},
	{"¡Ù","¡à","¡à","¡Ù","¡à","¡à","¡à","¡Ù","¡à","¡à"},
	{"¡Ù","¡à","¡à","¡Ù","¡à","¡Ù","¡à","¡Ù","¡Ù","¡à"}
};

const char* Buffer[col][row];
void Run();
void Check(int x, int y, const char* star);
void Print();

class CNode
{
	friend class Stack;
private:
	CNode()
	{
		Pnext = nullptr;
	}
	~CNode()
	{

	}
	typedef CNode* Pnode;

private:
	int iX;
	int iY;
	Pnode Pnext;
};

class Stack
{
public:
	Stack()
	{
		Size = 0;
		FIFO = nullptr;
	}
	~Stack()
	{
		Pnode  Tempo = FIFO;
		while (Tempo)
		{
			Pnode Alter = Tempo->Pnext;
			delete Tempo;
			Tempo = Alter;
		}
	}

	typedef CNode  Node;
	typedef CNode* Pnode;

private:
	int Size;
	Pnode FIFO;

public:
	void Push(int x, int y, const char* star)
	{
		Pnode Save = new Node;

		Save->iX = x;
		Save->iY = y;

		Save->Pnext = FIFO;

		FIFO = Save;
		Size++;

	}
	void Pop()
	{
		if (!Size)
			return;
		Pnode next = FIFO->Pnext;
		delete FIFO;
		FIFO = next;
		Size--;
	}

	int Top_iX()	const
	{
		return FIFO->iX;
	}
	int Top_iY()	const
	{
		return FIFO->iY;
	}

	int Size_H()
	{
		return Size;
	}

};

int main()
{
	Run();
}

void Check(int x, int y, const char* star)
{
	Stack Tempo;
	Tempo.Push(0, 0, star);

	do
	{

		int iX = Tempo.Top_iX();
		int iY = Tempo.Top_iY();

		if (iX < 0 || iX >= row)
		{
			Tempo.Pop();
			continue;
		}
		if (iY < 0 || iY >= col)
		{
			Tempo.Pop();
			continue;
		}
		if (Buffer[iY][iX] == star || Buffer[iY][iX] == "¡Ú")
		{
			Tempo.Pop();
			continue;
		}


		Buffer[iY][iX] = "¡Ú";


		Print();
		Tempo.Push(iX - 1, iY, star);
		Tempo.Push(iX + 1, iY, star);
		Tempo.Push(iX, iY - 1, star);
		Tempo.Push(iX, iY + 1, star);
	} while (Tempo.Size_H());




}

void Print()
{
	system("cls");
	for (int i = 0; i < col; i++)
	{
		for (int k = 0; k < row; k++)
		{
			cout << Buffer[i][k];
		}
		cout << endl;
	}
}

void Run()
{
	while (1)
	{
		for (int i = 0; i < col; i++)
		{
			for (int k = 0; k < row; k++)
			{
				Buffer[i][k] = Star[i][k];
			}
		}

		Print();
		Check(0, 0, "¡à");
		cout << "Àç ½ÃÀÛ ?  " << endl;
		cout << "The End = 5 Key" << endl;
		int num;
		cin >> num;
		if (num == 5)
			break;
		system("pause");
	}
}