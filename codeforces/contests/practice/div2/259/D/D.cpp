#include<bits/stdc++.h>
using namespace std;

const int M = 17;
const int N = 60;
const int INF = 1e9;
bool is(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> m;
    for (int i = 2, j = 1; i < N; i++) {
        if (is(i)) {
            m[i] = j;
            j *= 2;
        }
    }
    int Z = 1 << M;
    vector<int> f(N);
    for (int i = 1; i < N; i++) {
        for (auto& [k, v] : m) {
            if (i % k == 0) {
                f[i] |= v;
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(Z, INF));
    vector<vector<int>> b(n + 1, vector<int>(Z));
    vector<vector<int>> c(n + 1, vector<int>(Z));
    for (int j = 0; j < Z; j++) dp[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k < N; k++) {
            int x = ((1 << M) - 1) & (~f[k]);
            for (int s = x; s; s = (s - 1) & x) {
                int ndp = dp[i - 1][s] + abs(a[i] - k);
                if (dp[i][s | f[k]] > ndp) {
                    dp[i][s | f[k]] = ndp;
                    b[i][s | f[k]] = k;
                    c[i][s | f[k]] = s;
                }
            }
        }
    }
    int j = min_element(dp[n].begin(), dp[n].end()) - dp[n].begin();
    vector<int> o;
    for (int i = n; i > 0; i--) {
        o.push_back(b[i][j]);
        j = c[i][j];
    }
    while (!o.empty()) {
        cout << o.back() << " ";
        o.pop_back();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
