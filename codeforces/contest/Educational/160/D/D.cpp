#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3, -1);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] = max(arr[index], val);
        }
    }
    T query(int index) {
        T sum = -1;
        for (; index > 0; index -= (index & (-index))) {
            sum = max(sum, arr[index]);
        }
        return sum;
    }
};

vector<int> get(int n, vector<int> p) {
    auto b = p;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    fenwick<int> fen(b.size());
    vector<int> less(n);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(b.begin(), b.end(), p[i]) - b.begin() + 1;
        less[i] = fen.query(j - 1);
        fen.add(j, i);
    }
    return less;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    vector<int> less = get(n, p);
    vector<long long> dp(n), cum(n), pre(n);
    for (int i = 0; i < n; i++) {
        int j = less[i];
        if (j == -1) {
            dp[i] = (i ? pre[i - 1] : 0) + 1;
            cum[i] = dp[i];
        }
        else {
            dp[i] += cum[j] + pre[i - 1] - pre[j];
            cum[i] = dp[i] + cum[j];
        }
        dp[i] %= MOD;
        cum[i] %= MOD;
        pre[i] = (dp[i] + (i ? pre[i - 1] : 0)) % MOD;
    }
    long long ans = 0;
    int m = p[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] <= m) ans = (ans + dp[i]) % MOD;
        ans += MOD;
        m = min(m, p[i]);
    }
    cout << ans % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
