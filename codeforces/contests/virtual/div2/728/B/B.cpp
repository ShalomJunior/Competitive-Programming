#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    unordered_map<int, unordered_set<int>> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x].insert(i + 1);
    }
    long long ans = 0;
    for (int i = 3; i < 2 * n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j) continue;
            int x = j, y = i / j;
            for (auto it = h[x].begin(); it != h[x].end(); it++) {
                int id = i - *it;
                if (x == y) {
                    if (h[y].count(id) && id != *it) ans++;
                }
                else {
                    if (h[y].count(i - *it)) ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}