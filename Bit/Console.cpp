#include <iostream>
#define endl '\n'

using namespace std;
int main()
{

    unsigned char power = 255;
    int Count = 8;
    cout << power << " Binary Code Value : ";
    while (Count--)
    {
        if (power & 128)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        power = power << 1;
    } 

    cout << endl;
}

