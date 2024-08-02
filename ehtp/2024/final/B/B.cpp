#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
template<typename T>
class sum {
public:
    int n;
    vector<T> pref;
    sum(vector<T>& arr) {
        n = arr.size();
        pref.resize(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    T query(int l, int r) {
        assert(l >= 0 && r < n);
        return pref[r] - (l ? pref[l - 1] : 0);
    }
};

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<vector<int>> a(k + 1, vector<int>(n + 1));
    for (int j = 1; j <= n; j++) a[0][j] = 1;
    vector<sum<int>> S = { sum<int>(a[0]) };
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = S[i - 1].query(max(j - (d - 1), 1LL), min(j + (d - 1), n));
            a[i][j] -= a[i - 1][j];
            a[i][j] += MOD;
            a[i][j] %= MOD;
        }
        S.push_back(sum<int>(a[i]));
    }
    for (int j = 1; j <= n; j++) cout << a[k][j] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}