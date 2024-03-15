#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int S = 10;

vector<int> fib(S);

int main()
{
    int n, m;
    cin >> n >> m;
    fib[0] = 0, fib[1] = 1;
    int tr = fib[0] + fib[1];
    int res = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (i > 1)
        {
            fib[i % S] = tr;
            tr += fib[i % S];
            tr %= M;
        }
        if (i >= n - m && i < n)
        {
            cout << "sum here" << endl;
            res += fib[i % S];
            res %= M;
        }

        cout << "F[n] " << i << " = " << fib[i % S] << endl;
    }

    cout << res << endl;
}