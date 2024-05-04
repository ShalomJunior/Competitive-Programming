#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k; cin >> k;
    vector<vector<int>> a(k);
    map<int, vector<int>> h;
    for (int i = 0; i < k; i++) {
        int n; cin >> n;
        a[i].resize(n + 1);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][n] += a[i][j];
        }
        for (int j = 0; j < n; j++) {
            h[a[i][n] - a[i][j]].push_back(i);
        }
    }
    for (auto& [cnt, vec] : h) {
        vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
        if (vec.size() > 1) {
            int i = vec[0], j = vec[1];
            int x, y;
            for (int l = 0; l < a[i].size(); l++) {
                if (a[i][a[i].size() - 1] - a[i][l] == cnt) { x = l; break; }
            }
            for (int l = 0; l < a[j].size(); l++) {
                if (a[j][a[j].size() - 1] - a[j][l] == cnt) { y = l; break; }
            }
            cout << "YES" << endl;
            cout << i + 1 << " " << x + 1 << endl;
            cout << j + 1 << " " << y + 1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}