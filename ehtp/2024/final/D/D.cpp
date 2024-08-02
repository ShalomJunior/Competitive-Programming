#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> multiply(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    assert(a[0].size() == b.size());
    int m = a.size();
    int n = a[0].size();
    int p = b[0].size();
    vector<vector<int>> res(m, vector<int>(p, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j] % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

vector<vector<int>> pow(const vector<vector<int>>& a, int k) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    vector<vector<int>> base = a;
    while (k > 0) {
        if (k % 2 == 1) {
            res = multiply(res, base);
        }
        base = multiply(base, base);
        k /= 2;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> base(k + 1);
    base[0] = 1;
    int s = 1;
    for (int i = 1; i <= k; i++) {
        base[i] = s;
        s *= 2;
        s %= MOD;
    }
    if (n <= k) {
        cout << base[n] << endl;
        return;
    }
    vector<vector<int>> m(k, vector<int>(k));
    for (int i = 0; i < k - 1; i++)
        m[i][i + 1] = 1;
    for (int j = 0; j < k; j++) m[k - 1][j] = 1;
    vector<vector<int>> A(k, vector<int>(1));
    for (int i = 1; i <= k; i++) A[i - 1][0] = base[i];
    int p = n - k;
    auto res = multiply(pow(m, p), A);
    cout << res[k - 1][0] << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}