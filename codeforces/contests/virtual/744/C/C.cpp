#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;  cin >> n >> m >> k;
    int card[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            card[i][j] = (c == '.' ? 0 : 1);
        }
    }
    int match[n][m];
    memset(match, 0, sizeof(match));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool b = false;
            int d = 0;
            for (; i - d >= 0 && j - d >= 0 && j + d < m; d++) {
                if (!card[i - d][j - d] || !card[i - d][j + d]) {
                    break;
                }
                b |= d >= k;
            }
            if (b) {
                d = 0;
                for (; i - d >= 0 && j - d >= 0 && j + d < m; d++) {
                    if (!card[i - d][j - d] || !card[i - d][j + d]) break;
                    match[i - d][j - d] = match[i - d][j + d] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (card[i][j] != match[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}