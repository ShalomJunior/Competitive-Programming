#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, int> h;
    set<pair<int, int>> mn, mx;
    for (int i = 0; i < n; i++) {
        mn.insert({ 0, i + 1 });
        mx.insert({ 0, i + 1 });
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            mn.erase({ h[y], y });
            mx.erase({ h[y], y });
            h[y] += x;
            mn.insert({ h[y], y });
            mx.insert({ h[y], y });
        }
        else if (t == 2) {
            int x, y;
            cin >> x >> y;
            mn.erase({ h[y], y });
            mx.erase({ h[y], y });
            h[y] = max(h[y] - x, 0LL);
            mn.insert({ h[y], y });
            mx.insert({ h[y], y });
        }
        else if (t == 3) {
            int M = prev(mx.end())->first;
            auto it = mx.lower_bound({ M, 0 });
            cout << it->second << endl;
        }
        else {
            cout << mn.begin()->second << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}