#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
void gcdhcf(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
        if (a == 0)
            cout << b;
        else if (b == 0)
            cout << a;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    gcdhcf(a, b);
    return 0;
}