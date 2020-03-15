#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
using namespace std;

class CSort
{
public:
	static bool Order_Function(int src, int des)
	{
		return src < des;
	}

	static void Patition(int *sort, int left, int right)
	{
		if (left < right)
		{
			int Mid = Sort(sort, left, right);
			Patition(sort, left, Mid - 1);
			Patition(sort, Mid + 1, right);
		}
	}

	static int Sort(int *sort, int left, int right)
	{
		int L = left;
		int R = right;
		int Pivot = sort[right];

		while (L < R)
		{
			while ( Order_Function(sort[L], Pivot))
			{
				L++;
			}
			while (Order_Function(Pivot, sort[R]) || Pivot == sort[R])
			{
				R--;
			}

			if (L < R)
				Swap(sort[L], sort[R]);
		}

		Swap(sort[L], sort[right]);

		return L;
	}

	static void Swap(int &ps1, int &ps2)
	{
		int temp = ps1;
		ps1 = ps2;
		ps2 = temp;
	}
};
