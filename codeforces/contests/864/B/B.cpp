#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<int>> rev(n, vector<int>(n));
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            rev[n - 1 - i][n - 1 - j] = v[i][j];
        }
    }

    if (n == 1) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != rev[i][j]) {
                if (k < 1) {
                    cout << "NO" << endl;
                    return;
                }
                if (v[i][j]) {
                    v[i][j] = 0;
                    rev[n - 1 - i][n - 1 - j] = 0;
                }
                else {
                    v[i][j] = 1;
                    rev[n - 1 - i][n - 1 - j] = 1;
                }
                k--;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}