#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x[i] = x[i - 1] + a[i];
    }
    vector<int> b(n + 1);
    vector<int> y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        y[i] = y[i - 1] + b[i];
    }
    vector<int> c(n + 1);
    vector<int> z(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        z[i] = z[i - 1] + c[i];
    }
    int tot = x[n];
    int mn = (tot + 2) / 3;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(x.begin(), x.end(), x[i - 1] + mn);
        A[i] = (it == x.end() ? n + 1 : it - x.begin());
    }
    vector<int> B(n + 1);
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(y.begin(), y.end(), y[i - 1] + mn);
        B[i] = (it == y.end() ? n + 1 : it - y.begin());
    }
    vector<int> C(n + 1);
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(z.begin(), z.end(), z[i - 1] + mn);
        C[i] = (it == z.end() ? n + 1 : it - z.begin());
    }
    map<int, vector<int>> h;
    h[0] = A;
    h[1] = B;
    h[2] = C;
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    do {
        bool flag = true;
        map<int, pair<int, int>> ans;
        int start = 1;
        for (auto id : p) {
            if (start > n || h[id][start] > n) {
                flag = false;
                break;
            }
            ans[id] = { start, h[id][start] };
            start = h[id][start] + 1;
        }
        if (flag) {
            for (auto id : { 0, 1, 2 }) {
                cout << ans[id].first << " " << ans[id].second << " ";
            }
            cout << endl;
            return;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
