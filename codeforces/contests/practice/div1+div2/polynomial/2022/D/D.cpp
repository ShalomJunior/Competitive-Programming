#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1));
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            tot += a[i][j];
            a[i][m] += a[i][j];
        }
    }
    if (tot % n) {
        cout << -1 << endl;
        return;
    }
    int k = tot / n;
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        if (a[i][m] > k) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    pos[j].push_back(i);
                }
            }
        }
    }
    int ans = 0;
    stringstream ss;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m && a[i][m] < k; j++) {
            if (a[i][j] == 0) {
                while (!pos[j].empty()) {
                    int ni = pos[j].back();
                    if (a[ni][m] == k) {
                        pos[j].pop_back();
                        continue;
                    }
                    ans++;
                    ss << i + 1 << " " << ni + 1 << " " << j + 1 << endl;
                    swap(a[i][j], a[ni][j]);
                    a[ni][m]--;
                    a[i][m]++;
                    pos[j].pop_back();
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
