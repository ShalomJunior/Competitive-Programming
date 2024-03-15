#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    unordered_map<int, int>d;
    dec(n, d);
    int ans = 1;
    for (auto& [k, v] : d) ans *= (v + 1);
    cout << ((n == 1) ? n : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while (n--)solve();
}