#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        b.insert(x);
    }
    int x = 0, y = 0;
    for (int i = 1; i <= k; i++) {
        if (!a.count(i) && !b.count(i)) {
            cout << "NO" << endl;
            return;
        }
        if (a.count(i))x++;
        if (b.count(i))y++;
    }
    cout << (x >= k / 2 && y >= k / 2 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
