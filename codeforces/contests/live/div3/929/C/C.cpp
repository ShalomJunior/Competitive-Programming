#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    set<int> vals;
    for (int i = 0; i <= log(l) / log(a) + 1; i++) {
        int f = pow(a, i);
        for (int j = 0; j <= log(l) / log(b) + 1; j++) {
            int s = pow(b, j);
            if (s > l / f) break;
            vals.insert(f * s);
        }
    }
    set<int> ans;
    for (int i = 1; i * i <= l; i++) {
        if (l % i) continue;
        if (vals.count(i))ans.insert(l / i);
        if (vals.count(l / i))ans.insert(i);
    }
    cout << ans.size() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
