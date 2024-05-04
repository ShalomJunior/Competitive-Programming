#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int cnt = count(a.begin(), a.end(), x);
    if (cnt == n) {
        cout << 0 << endl;
        return;
    }
    int sum = n * x - accumulate(a.begin(), a.end(), 0LL);
    if (cnt || sum == 0) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}