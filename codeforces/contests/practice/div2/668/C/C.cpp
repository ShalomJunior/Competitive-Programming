#include <bits/stdc++.h>
using namespace std;

const int N = 9;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    vector<set<int>> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = set<int>(b.begin(), b.end());
    }
    int ans = 0;
    for (int i = N; i >= 0; i--) {
        int mask = 1 << i;
        vector<bool> good(n);
        for (int j = 0; j < n; j++) {
            if (((a[j] >> i) & 1) == 0) {
                good[j] = true;
                continue;
            }
            for (auto it = pos[j].begin(); it != pos[j].end(); it++) {
                if (((*it >> i) & 1) == 0) {
                    good[j] = true;
                    break;
                }
            }
        }
        if (count(good.begin(), good.end(), false)) {
            ans |= (1 << i);
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (((a[j] >> i) & 1) == 0) continue;
            vector<int> to_del;
            for (auto it = pos[j].begin(); it != pos[j].end(); it++) {
                if ((*it >> i) & 1) {
                    to_del.push_back(*it);
                }
            }
            for (auto& c : to_del) pos[j].erase(c);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
