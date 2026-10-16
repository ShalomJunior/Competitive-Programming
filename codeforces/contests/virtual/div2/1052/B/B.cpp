#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> a(n);
    vector<int> idx(m + 1, -1);
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a[i].insert(x);
            cnt[x]++;
            idx[x] = i;
        }
    }
    for (int j = 1; j <= m; j++) {
        if (cnt[j] == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (auto& c : a[i]) {
            if (cnt[c] == 1) {
                flag = false;
            }
        }
        ans += flag;
    }
    cout << (ans >= 2 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}