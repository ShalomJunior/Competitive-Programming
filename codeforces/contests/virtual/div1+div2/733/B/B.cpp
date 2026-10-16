#include<bits/stdc++.h>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j]) continue;
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                ans++;
                for (int di : {-1, 0, 1}) {
                    for (int dj : {-1, 0, 1}) {
                        if (di == dj && di == 0) continue;
                        int ni = i + di;
                        int nj = j + dj;
                        if (0 <= ni && ni < h && 0 <= nj && nj < w) a[ni][nj] = 1;
                    }
                }
            }
            else {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (a[i][j] ^ 1);
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}