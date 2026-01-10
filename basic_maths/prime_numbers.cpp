#include <iostream>
#include <stdlib.h>
using namespace std;
void prime_checker(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
            {
                count++;
            }
        }
    }
    if (count == 2)
    {
        cout << "Prime";
        //  return 1;
    }
    else
    {
        cout << "Not Prime";
        // return 0;
    }
}
int main()
{
    int n;
    cin >> n;
    prime_checker(n);
    return 0;
}