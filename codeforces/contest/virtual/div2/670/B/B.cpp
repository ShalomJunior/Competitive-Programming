#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<int> b;
    if (n <= 10) b = a;
    else {
        for (int i = 0; i < 5; i++) {
            b.push_back(a[i]);
            b.push_back(a[n - 1 - i]);
        }
    }
    sort(b.begin(), b.end());
    int m = b.size();
    long long ans = -INF;
    for (int i = 0; i < (1 << m); i++) {
        if (__builtin_popcount(i) != 5) continue;
        long long x = 1;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                x *= b[j];
            }
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}