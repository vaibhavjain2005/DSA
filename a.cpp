#include <iostream>
using namespace std;

int modExp(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;

    for (int i = 0; i < exp; i++)
        result = (result * base) % mod;

    return result;
}

int modInverse(int x, int q)
{
    int n = q, phi = q;

    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            phi -= phi / p;
        }
    }

    if (n > 1)
        phi -= phi / n;

    int exp = phi - 1;
    int result = 1;
    x %= q;

    while (exp > 0)
    {
        if (exp % 2)
            result = (result * x) % q;

        x = (x * x) % q;
        exp /= 2;
    }

    return result;
}

int main()
{
    int hm, p, q, e0, d, r;

    cout << "Enter p: ";
    cin >> p;
    cout << "Enter q: ";
    cin >> q;
    cout << "Enter e0: ";
    cin >> e0;
    cout << "Enter d: ";
    cin >> d;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter h(m): ";
    cin >> hm;

    int e1 = modExp(e0, (p - 1) / q, p);
    int e2 = modExp(e1, d, p);

    int s1 = modExp(e1, r, p) % q;
    int s2 = ((hm + d * s1) * modInverse(r, q)) % q;

    cout << "Public key: (" << e1 << ", " << e2 << ", " << p << ", " << q << ")" << endl;
    cout << "sig1: " << s1 << endl;
    cout << "sig2: " << s2 << endl;

    int w = modInverse(s2, q);
    int a = (hm * w) % q;
    int b = (s1 * w) % q;

    int V = ((modExp(e1, a, p) * modExp(e2, b, p)) % p) % q;

    cout << "V: " << V << endl;

    if (V == s1)
        cout << "Signature Verified" << endl;
    else
        cout << "Signature Invalid" << endl;

    return 0;
}