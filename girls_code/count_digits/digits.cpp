#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, b;
    cin >> n >> b;

    long long cn = 1;
    for (int i = 1; i < log(n) / log(b) + 1; i++)
        cn += (b - 1) * i + 1;

    cout << cn << endl;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
        solve();
}