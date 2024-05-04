#include <bits/stdc++.h>
using namespace std;

const int N = 31;
const int INF = 2e9;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> id(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (a[i] & mask)id[j].push_back(i);
        }
    }
    int ans = 0;
    bool flag = false;
    for (int j = N - 1; j >= 0; j--) {
        int mask = 1 << j;
        int m = id[j].size();
        if (x & mask) {
            flag = true;
            if (m % 2 == 0 && m > 0) {
                cerr << "j = " << j << endl;
                cerr << "m = " << m << endl;
                int x = m / 2;
                if (id[j][0]) x++;
                if (id[j].back() != n - 1 && id[j].back() != id[j][1]) x++;
                cerr << "x = " << x << endl;
                ans = max(ans, x);
            }
        }
        else {
            if (!flag && m & 1) {
                cout << -1 << endl;
                return;
            }
        }
    }
    // int ans = 0;
    // int start = 0;
    // while (start < n) {
    //     int z = seg.size();
    //     int mx = start;
    //     for (int i = 0; i < z; i++) {
    //         auto it = lower_bound(seg[i].begin(), seg[i].end(), start);
    //         if (it == seg[i].end()) {
    //             mx = n;
    //             break;
    //         }
    //         mx = max(mx, *it);
    //     }
    //     if (mx < n) ans++;
    //     start = mx + 1;
    // }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
