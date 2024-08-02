#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& c : h) cin >> c;
    vector<int> t(n);
    t[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (h[i] == 0) continue;
        if (h[i] <= h[i + 1]) {
            t[i] = t[i + 1] + 1;
        }
        else {
            t[i] = max(h[i], t[i + 1] + 1);
        }
    }
    cout << *max_element(t.begin(), t.end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
