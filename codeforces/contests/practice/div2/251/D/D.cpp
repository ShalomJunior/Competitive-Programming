#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    set<int> s;
    vector<int> a(n), b(m);
    for (auto& c : a) {
        cin >> c;
        s.insert(c);
    }
    for (auto& c : b) {
        cin >> c;
        s.insert(c);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> A(n + 1), B(m + 1);
    for (int i = 1; i <= n; i++) A[i] = A[i - 1] + a[i - 1];
    for (int i = 1; i <= m; i++) B[i] = B[i - 1] + b[i - 1];
    auto get = [&](vector<int>& X, int l, int r) {
        return X[r] - X[l - 1];
        };
    int ans = INF;
    for (auto& c : s) {
        int curr = 0;
        auto it1 = lower_bound(a.begin(), a.end(), c);
        int j = it1 - a.begin();
        if (j) {
            curr += j * c - get(A, 1, j);
        }
        auto it2 = upper_bound(b.begin(), b.end(), c);
        j = it2 - b.begin();
        if (j < m) {
            int cnt = m - j;
            curr += get(B, m - cnt + 1, m) - cnt * c;
        }
        ans = min(ans, curr);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
