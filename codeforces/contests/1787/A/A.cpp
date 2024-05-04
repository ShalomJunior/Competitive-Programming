#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << 1 << " " << n / 2 << endl;
    else
        cout << -1 << endl;
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        solve();
}