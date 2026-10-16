#include <bits/stdc++.h>
using namespace std;

const int N = 4;
const string S = "1543";
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    auto get = [&](int k) {
        string s;
        for (int j = k; j <= m - 1 - k; j++) s += g[k][j];
        for (int i = k + 1; i < n - 1 - k; i++) s += g[i][m - 1 - k];
        for (int j = m - 1 - k; j >= k; j--) s += g[n - 1 - k][j];
        for (int i = n - k - 2; i > k; i--) s += g[i][k];
        return s;
        };
    int cnt = 0;
    for (int i = 0; i < min(n / 2, m / 2); i++) {
        auto r = get(i);
        int z = r.size();
        r += r;
        for (int i = 0; i < z && i + N <= r.size(); i++) {
            if (r.substr(i, N) == S)
                cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
