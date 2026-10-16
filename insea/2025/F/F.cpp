#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int r = b[0] % a[0];
    if (r) return true;
    int k = b[0] / a[0];
    bool res = true;
    for (int i = 0; i < n; i++) {
        res &= (b[i] == k * a[i]);
    }
    return !res;
}

int go(vector<vector<int>> a) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> in;
    in.push_back(a[0]);
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < (int)in.size(); j++) {
            flag &= check(in[j], a[i]);
        }
        if (flag) in.push_back(a[i]);
    }
    return in.size();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    cout << min(go(a), go(b)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
