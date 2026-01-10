#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool armstrong_number(int n)
{
    int sum = 0, last_digit, a = n;
    while (n > 0)
    {
        last_digit = n % 10;
        sum = sum + pow(last_digit, 3);
        n = n / 10;
    }
    if (a == sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    cout << armstrong_number(n);
    return 0;
}