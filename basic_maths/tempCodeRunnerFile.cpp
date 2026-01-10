#include <iostream>
using namespace std;
size_t reverse_a_number(size_t n)
{
    size_t reverse_num = 0;
    int last_digit;
    while (n > 0)
    {
        last_digit = n % 10;
        n = n / 10;
        reverse_num = reverse_num * 10 + last_digit;
    }
    return reverse_num;
}
int main()
{
    size_t n;
    cin >> n;
    reverse_a_number(n);
    return 0;
}