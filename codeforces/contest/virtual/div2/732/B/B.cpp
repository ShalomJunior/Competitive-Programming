#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(N));
    for (int i = 0; i < 2 * n - 1; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[j][s[j] - 'a']++;
        }
    }
    string ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] % 2) {
                ans += (char)('a' + j);
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}