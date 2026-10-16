#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int lim = (m + 1) / 2;
    vector<vector<int>> a(m);
    map<int, int> h;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        h[a[i][0]]++;
    }
    int id = -1;
    int cnt = 0;
    for (auto& [k, v] : h) {
        if (v > cnt) {
            id = k;
            cnt = v;
        }
    }
    for (int i = 0; i < m && cnt > lim; i++) {
        if (a[i][0] == id && a[i].size() > 1) {
            swap(a[i][0], a[i][1]);
            cnt--;
        }
    }
    if (cnt > lim) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; i++) cout << a[i][0] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}