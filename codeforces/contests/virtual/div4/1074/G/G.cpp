#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
int mex(vector<int> a, int add = INF) {
    set<int> s(a.begin(), a.end());
    s.insert(add);
    int ans = 0;
    while (s.count(ans)) ans++;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> x(n), y(n);
    map<int, int> mpx, mpy, cnt;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        x[i] = mex(a[i]);
        y[i] = mex(a[i], x[i]);
        cnt[x[i]]++;
        mpx[x[i]] += x[i];
        mpy[x[i]] += y[i];
    }
    int all = accumulate(x.begin(), x.end(), 0LL);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            int mex = x[i];
            if ((j - 1 >= 0 && a[i][j - 1] == a[i][j]) || (j + 1 < (int)a[i].size() && a[i][j + 1] == a[i][j])) {}
            else {
                mex = min(x[i], a[i][j]);
            }
            int yes = cnt[a[i][j]];
            int no = n - 1 - cnt[a[i][j]];
            ans += yes * (all + mex - x[i]) + mpy[a[i][j]] - mpx[a[i][j]];
            ans += no * (all + mex - x[i]);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}