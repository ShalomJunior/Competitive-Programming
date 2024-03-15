#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
ll qp(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
ll a[50003], d[50003];
#define S 1000

int main()
{
    for (int i = 1; i <= S; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            if (i % j == 0) d[i] += j;
        }
        d[i] %= MOD;
    }
    a[0] = 1;
    for (int i = 1; i <= S; i++)
    {
        ll qwq = 0;
        for (int j = 0; j < i; j++) qwq = qwq + d[i - j] * a[j] % MOD;
        qwq %= MOD;
        a[i] = qwq * qp(i, MOD - 2) % MOD;
    }
    /*
    int n;
    while (cin >> n) {
        cout << a[n] << "\n";
    }*/
    for (int i = 0; i < 100; i++) cout << a[i] - 1 << "\n";
}