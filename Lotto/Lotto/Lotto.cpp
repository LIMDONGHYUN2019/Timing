#include"Sort.h"

int main()
{
	srand((unsigned int)time(NULL));
	rand();
	int LottoNumber[7] = { 0,};
	int MyNumber[6] = { 0,};
	bool Flag[45] = { 0, };
	int Finish = 0;
	
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &MyNumber[i]);
	}

	int Count = 0, FlagValue;

	while (Count < 7)
	{
		FlagValue = rand() % 45;
		if (!Flag[FlagValue])
		{
			LottoNumber[Count] = FlagValue + 1;
			Flag[FlagValue] = true;
			Count++;
		}
	}
	CSort::Patition(MyNumber, 0, sizeof(MyNumber) / sizeof(int) - 1);
	CSort::Patition(LottoNumber, 0, sizeof(LottoNumber) / sizeof(int) - 2);
	
	system("cls");
	printf("My Lotto Number :\t");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", MyNumber[i]);
	}
	printf("\nBank Lotto Number :\t");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", LottoNumber[i]);
	}
	printf(" /  %d\n", LottoNumber[6]);

	
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (MyNumber[i] == LottoNumber[k])
			{
				Finish += 2;
			}
		}
		if (MyNumber[i] == LottoNumber[6])
		{
			Finish += 1;
		}
	}

	printf("\n당첨결과 !!!!! : ");
	switch (Finish / 2)
	{
	case 6:
		printf("WOW... 1 등이다!!!!.\n");
		break;
	case 5:
		if(Finish % 2)
			printf("Good !! 2 등이다....\n");
		else
			printf("Good !! 3 등이다....\n");
		break;
	case 4:
		printf("4 등이다....\n");
		break;
	case 3:
		printf("5 등이다....\n");
		break;
	default:
		printf("Noting....\n");
		break;
	}
}

