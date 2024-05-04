#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if (k == 1) {
        cout << "YES" << endl;
        return;
    }
    vector<int> pos;
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == a[0][0]) {
                pos.push_back(j);
                break;
            }
        }
    }
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    if (pos.size() > 2) {
        cout << "NO" << endl;
        return;
    }
    if (pos.size() == 2 && pos[1] - pos[0] != 1) {
        cout << "NO" << endl;
        return;
    }
    auto go = [&](int p) {
        if (p < 0) return false;
        vector<int> match;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (match.size() == p) {
                match.push_back(a[0][0]);
                flag = true;
            }
            match.push_back(a[0][i]);
        }
        if (!flag) match.push_back(a[0][0]);
        assert((int)match.size() == n);
        for (int i = 0; i < k; i++) {
            vector<int> cmp;
            cmp.push_back(a[i][0]);
            for (int j = 0; j < n; j++) {
                if (match[j] != a[i][0]) cmp.push_back(match[j]);
            }
            if (cmp != a[i]) return false;
        }
        return true;
        };
    for (int i : {pos[0] - 1, pos[0], pos[0] + 1}) {
        if (go(i)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
