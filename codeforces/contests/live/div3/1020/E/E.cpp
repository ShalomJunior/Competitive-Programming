#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (pos[x] < l || pos[x] > r) {
            cout << -1 << " ";
            continue;
        }
        int miss_less = 0;
        int miss_great = 0;
        int less = 0;
        int great = 0;
        while (true) {
            int m = (l + r) / 2;
            if (pos[x] < m) {
                great++;
                if (p[m] < x) miss_great++;
                r = m - 1;
            }
            else if (pos[x] == m) {
                break;
            }
            else if (pos[x] > m) {
                less++;
                if (p[m] > x) miss_less++;
                l = m + 1;
            }
        }
        if (less >= x || (n - x) < great) {
            cout << -1 << " ";
        }
        else {
            cout << max(miss_less, miss_great) * 2 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
