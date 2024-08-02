#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    char a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    char b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i + 1 < n; i++) {
        for (int j = 1; j + 1 < n; j++) {
            if (a[i][j] != b[i][j]) continue;
            if (a[i - 1][j] == b[i - 1][j]) continue;
            if (a[i + 1][j] == b[i + 1][j]) continue;
            if (a[i][j - 1] == b[i][j - 1]) continue;
            if (a[i][j + 1] == b[i][j + 1]) continue;
            cout << i + 1 << " " << j + 1 << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}