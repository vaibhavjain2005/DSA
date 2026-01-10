#include <iostream>
#include <stdlib.h>
using namespace std;
void explainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;
    pair<int, pair<int, int>> a = {1, {1, 3}};
    cout << a.second.first << " " << a.second.second;
}
int main()
{
    explainPair();
    return 0;
}