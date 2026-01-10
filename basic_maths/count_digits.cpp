#include <iostream>
using namespace std;

int main()
{
    size_t n;
    cin >> n;
    size_t last_digit, number = n, count = 0;
    while (number > 0)
    {
        last_digit = n % 10;
        number = number / 10;
        count++;
    }
    cout << "The number of digits the number " << n << " has is " << count << endl;
    return 0;
}