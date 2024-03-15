#include <bits/stdc++.h>

using namespace std;

bool perfect(long long n)
{
    long long a = sqrt(n);
    return (n == a * a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin >> k;
    long long a = 0;
    long long b, s;
    for (; a < k; a++)
    {
        b = 1 + 2 * a;
        long long d = b * b + 8 * k;
        if (perfect(d))
        {
            s = sqrt(d);
            if ((s - b) % 2 == 0)
                break;
        }
    }

    cout << a + 1 << " " << a + (s - b) / 2;

    return 0;
}