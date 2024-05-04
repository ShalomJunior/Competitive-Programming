#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < n * n; i++) {
        int a; cin >> a;
        h[a]++;
    }
    set<Mine> s;
    for (auto& [k, v] : h) {
        s.insert({ v, k });
    }
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            set<Mine> id;
            id.insert({ i, j }); id.insert({ i, n - 1 - j });
            id.insert({ n - 1 - i, j }); id.insert({ n - 1 - i, n - 1 - j });
            auto p = *prev(s.end());
            if (p.F < id.size()) {
                cout << "NO" << endl;
                return;
            }
            for (auto it = id.begin(); it != id.end(); ++it) {
                int x = it->F, y = it->S;
                ans[x][y] = p.S;
            }
            s.erase(prev(s.end()));
            p.F -= id.size();
            if (p.F) s.insert(p);
        }
    }
    if (n & 1) {
        for (int i = 0; i < n / 2; i++) {
            auto p = *prev(s.end());
            if (p.F < 2) {
                cout << "NO" << endl;
                return;
            }
            ans[n / 2][i] = ans[n / 2][n - 1 - i] = p.S;
            s.erase(prev(s.end()));
            p.F -= 2;
            if (p.F) s.insert(p);
        }
        for (int i = 0; i < n / 2; i++) {
            auto p = *prev(s.end());
            if (p.F < 2) {
                cout << "NO" << endl;
                return;
            }
            ans[i][n / 2] = ans[n - 1 - i][n / 2] = p.S;
            s.erase(prev(s.end()));
            p.F -= 2;
            if (p.F) s.insert(p);
        }
        ans[n / 2][n / 2] = s.begin()->S;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}