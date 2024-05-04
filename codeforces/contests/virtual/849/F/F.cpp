#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    vector<int> rest(n, 3);
    set<int> s;
    for (int i = 0; i < n; i++)s.insert(i);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            --l; --r;
            vector<int> to_del;
            for (auto it = s.lower_bound(l); it != s.end() && *it <= r; it++) {
                if (!(--rest[*it])) to_del.push_back(*it);
                a[*it] = f(a[*it]);
            }
            for (auto& c : to_del)s.erase(c);
        }
        else {
            int x; cin >> x;
            cout << a[--x] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}