#include <bits/stdc++.h>
using namespace std;

const int R = 8, C = 8;
void solve() {
    vector<vector<char>> a(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        if (a[i][0] == '.' || a[i][0] == 'B') continue;
        bool b = true;
        for (int j = 1; j < C; j++) b &= (a[i][j] == a[i][0]);
        if (b) { cout << a[i][0] << endl; return; }
    }
    for (int j = 0; j < C; j++) {
        if (a[0][j] == '.' || a[0][j] == 'R') continue;
        bool b = true;
        for (int i = 1; i < R; i++)b &= (a[i][j] == a[0][j]);
        if (b) { cout << a[0][j] << endl; return; }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}