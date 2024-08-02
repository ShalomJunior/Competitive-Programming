#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int, int> f(int n) {
    int id = 0;
    int m = 1;
    while (m < n) {
        m <<= 1, id++;
        assert(id < 61);
    }
    return { id, m };
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> power(n, 1);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == 1) {
            if (a[i - 1] > 1) {
                cout << -1 << endl;
                return;
            }
            else {
                continue;
            }
        }
        power[i] = ceil(power[i - 1] * log(a[i - 1]) / log(a[i]));
        auto p = f(power[i]);
        power[i] = p.second;
        ans += p.first;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}