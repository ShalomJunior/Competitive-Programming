#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2), pre(n + 2);
    map<int, vector<int>> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n + 1; i++) {
        pre[i] = pre[i - 1] ^ a[i];
        h[pre[i]].push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        assert(r - l + 1 >= 2);
        if (pre[l - 1] == pre[r]) {
            cout << "YES" << endl;
        }
        else {
            int x = pre[l - 1] ^ pre[r];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}