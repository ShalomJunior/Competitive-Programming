#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), x(n);
    for (auto& c : a) cin >> c;
    for (auto& c : x) cin >> c;
    vector<Mine> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i].F = a[i] * (i + 1) * (n - i);
        vec[i].S = i;
    }
    sort(vec.begin(), vec.end());
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) {
        b[vec[i].S] = x.back();
        x.pop_back();
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ((a[i] * (i + 1) * (n - i)) % MOD) * b[i];
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}