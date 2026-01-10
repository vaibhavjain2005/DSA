#include <iostream>
using namespace std;
int sum_n(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum_n(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << sum_n(n);
    return 0;
}