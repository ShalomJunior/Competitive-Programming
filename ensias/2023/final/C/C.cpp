#include <bits/stdc++.h>

using namespace std;

int last_digits(long long a, long long b)
{
    if (b == 0)
        return 1;
    while (b > 0)
    {
        a %= 1000;
        int ex = log(LONG_LONG_MAX) / log(a);
        if (b <= ex)
        {
            long long temp = pow(a, b);
            temp %= 1000;
            return temp;
        }
        pow(a, ex);
        b = b / ex + b % ex;
    }

    return a % 1000;
}

int first_digit(long long a, long long b)
{
    int digits = 3;
    double x, y;

    x = b * log10(a);
    y = floor(pow(10, x - floor(x) + digits - 1));

    return (int)y;
}

void solve()
{
    long long a, b;
    cin >> a >> b;

    cout << first_digit(a, b) + last_digits(a, b) << endl;
    cout << "first digits : " << first_digit(a, b) << endl;
    cout << "Last digits : " << last_digits(a, b) << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
}