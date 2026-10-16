#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
int f(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= min(a[i], b[i]);
        ans %= MOD;
    }
    return ans;
}

int power(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int inv(int a, int mod) {
    return power(a, mod - 2, mod);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    vector<int> pa(n), pb(n);
    iota(pa.begin(), pa.end(), 0);
    iota(pb.begin(), pb.end(), 0);
    sort(pa.begin(), pa.end(), [&](const int& i, const int& j) {
        return a[i] < a[j];
        });
    sort(pb.begin(), pb.end(), [&](const int& i, const int& j) {
        return b[i] < b[j];
        });
    map<int, int> ha, hb;
    for (int i = 0; i < n; i++) ha[pa[i]] = i;
    for (int i = 0; i < n; i++) hb[pb[i]] = i;
    vector<int> na(n, n - 1), nb(n, n - 1);
    for (int i = n - 2; i >= 0; i--) {

    }

    int P = f(a, b);
    cout << P << " ";
    while (q--) {
        int o, x;
        cin >> o >> x;
        x--;
        if (o == 1) {
            a[x]++;
            int j = ha[x];
            int nj = j;
            while (nj + 1 < n && a[pa[nj + 1]] < a[x]) nj++;
            int old = min(a[x] - 1, b[pb[nj]]);
            int next = min(a[x], b[pb[nj]]);
            P = P * inv(old, MOD) % MOD;
            P = P * next % MOD;
            if (nj != j) {
                ha[pa[nj]] = j;
                ha[pa[j]] = nj;
                swap(pa[j], pa[nj]);
            }
        }
        else {
            b[x]++;
            int j = hb[x];
            int nj = j;
            while (nj + 1 < n && b[pb[nj + 1]] < b[x]) nj++;
            int old = min(b[x] - 1, a[pa[nj]]);
            int next = min(b[x], a[pa[nj]]);
            P = P * inv(old, MOD) % MOD;
            P = P * next % MOD;
            if (nj != j) {
                hb[pb[nj]] = j;
                hb[pb[j]] = nj;
                swap(pb[j], pb[nj]);
            }
        }
        cout << P << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}