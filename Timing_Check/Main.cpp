#include<iostream>
#include<Windows.h>
#include<time.h>
#include<iomanip>
#include<conio.h>
#define endl '\n'

using namespace std;

int main()
{
   //while (1)
   //{
   //    int StartTime;
   //    StartTime = GetTickCount();
   //    while (GetTickCount() - StartTime < 1000)
   //    {

   //    }
   //    printf("1초마다 한번씩 실행됩니다\n");
   //}

    int Timing[] = { 5, 7, 10, 14, 17, 20, 23, 25, 28 };
    const char* Check[9] = { "-", "-", "-", "-", "-", "-", "-", "-", "-" };
    int Count = 0, G;

    while (1)
    {
       int first = clock();
       if (_kbhit())
       {
           _getch();

           if (Count > 8)
               continue;

           G = abs(Timing[Count] * CLOCKS_PER_SEC - first);

           Check[Count] = "=";
           
           

           if (G < 1000)
           {
               if (G > 700)
                   Check[Count] = "Bad";
               else if (G > 500)
                   Check[Count] = "Good";
               else if (G > 300)
                   Check[Count] = "Great";
               else if (G >= 0)
                   Check[Count] = "Perfect";
           }
           else
               Check[Count] = "Failed";
           Count++;
       }

       if (first / CLOCKS_PER_SEC > Timing[Count])
       {
           Check[Count] = "Failed";
           Count++;
       }

       printf("%07.3f %s\n\n", (float)first / CLOCKS_PER_SEC, "Sec");

       for (int i = 0; i < sizeof(Timing) / 4; i++)
       {
           cout << Timing[i] << " Sec : " << Check[i] << endl;

       }

       cout << G << endl;
       system("cls");
    }

}