#include <bits/stdc++.h>
using namespace std;

const int N = 25;
long long fact[N];

void solve() {
    int n; cin >> n;
    long long split = fact[n] / (2LL * fact[n / 2] * fact[n / 2]);
    int ways = fact[n / 2 - 1];
    cout << split * ways * ways << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;
    solve();
}