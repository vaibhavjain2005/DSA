#include <iostream>
using namespace std;
void sumn(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sumn(i - 1, sum + i);
}
int main()
{
    int n;
    cin >> n;
    sumn(n, 0);
    return 0;
}