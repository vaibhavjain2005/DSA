#include <iostream>
#include <string.h>
using namespace std;
void print_name_n_times(int n, string s)
{
    if (n == 0)
    {
        return;
    }
    cout << s << endl;
    n--;
    print_name_n_times(n, s);
}
int main()
{
    int n;
    string s;
    cin >> n >> s;

    print_name_n_times(n, s);
    return 0;
}