#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    map<int, int> r;
    map<int, int> c;
    int b[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            if (a[i][j] != b[i][j]) {
                r[i]++;
                c[j]++;
            }
        }
    }
    for (auto& [k, v] : r) {
        if (v & 1) {
            cout << "NO" << endl;
            return;
        }
    }
    for (auto& [k, v] : c) {
        if (v & 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}