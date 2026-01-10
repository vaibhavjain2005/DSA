#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
void print_all_divisors(int n)
{
    for (size_t i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void print_all_divisors2(int n)
{
    vector<int> ls;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            if ((n / i) != i)
            {
                ls.push_back(n / i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for (auto it : ls)
        cout << it << " ";
}
int main()
{
    int n;
    cin >> n;
    print_all_divisors(n);
    print_all_divisors2(n);
    return 0;
}