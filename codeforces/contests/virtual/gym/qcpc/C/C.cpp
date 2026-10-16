#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 5;
bool g[N][4];
void solve() {
    int n;
    cin >> n;
    cout << (g[n][0] ? "Anne" : "Brian") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= 3; j++) {
            bool ok = false;
            for (int k = 1; k <= 3; k++) {
                if (abs(j - k) != 2 && j != k) ok |= g[i - j][k];
            }
            if (!ok) g[i][j] = g[i][0] = 1;
        }
    }
    for (int i = 1; i < 100; i++) {
        cout << (g[i][0] ? "Anne" : "Brian") << endl;

    }
    int t; cin >> t;
    while (t--) solve();
}
