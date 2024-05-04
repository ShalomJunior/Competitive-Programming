#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans[n][n];
    memset(ans, 0, sizeof(ans));
    ans[0][0] = ans[n - 1][n - 1] = 1;
    int r = n - 2;
    int nxt = 1;
    int last = 0;
    for (int j = 1; j < n && r; j++) {
        if (last + nxt - 1 < n) {
            ans[last + nxt - 1][j] = 1;
            last = last + nxt - 1;
        }
        else {
            ans[last - (nxt - 1)][j] = 1;
            last = last - (nxt - 1);
        }
        r--;
        nxt++;
    }
    // vector<pair<int, int>> all;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (ans[i][j]) {
    //             cout << i + 1 << " " << j + 1 << endl;
    //         }
    //     }
    // }
    // cout << endl;
    vector<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j]) all.push_back({ i, j });
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    set<int> cnt;
    int z = all.size();
    for (int i = 0; i < z;i++) {
        for (int j = 0; j < n; j++) {
            cnt.insert(abs(all[i].first - all[j].first) + abs(all[j].second - all[i].second));
        }
    }
    cerr << "Z = " << cnt.size() << endl;
    for (auto it = cnt.begin();it != cnt.end(); it++) cout << *it << " ";
    cout << endl;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
