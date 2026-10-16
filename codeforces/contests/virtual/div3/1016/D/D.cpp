#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string t;
        cin >> t;
        if (t == "->") {
            int x, y;
            cin >> x >> y;
            auto go = [&](int id, int i, int j) {

                };
            go(0);
        }
        else if (t == "<-") {
            int d;
            cin >> d;
        }
        else {
            assert(false);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}