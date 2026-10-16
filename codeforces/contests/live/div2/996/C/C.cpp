#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> x(n);
    vector<int> y(m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            x[i] += a[i][j];
            y[j] += a[i][j];
        }
    }
    int z = n + m - 2;
    map<int, int> r, c;
    int di = 0;
    int dj = 0;
    r[di]++;
    c[dj]++;
    for (int i = 0; i < z; i++) {
        s[i] == 'D' ? di++ : dj++;
        r[di]++;
        c[dj]++;
    }
    int S = r[0] == 1 ? x[0] : y[0];
    r[0]--;
    c[0]--;
    di = 0;
    dj = 0;
    auto b = a;
    for (int i = 0; i < z; i++) {
        s[i] == 'D' ? di++ : dj++;
        if (r[di] == 1) {
            b[di][dj] = S - x[di];
        }
        else if (c[dj] == 1) {
            b[di][dj] = S - y[dj];
        }
        else {
            assert(false);
        }
        x[di] += b[di][dj] - a[di][dj];
        y[dj] += b[di][dj] - a[di][dj];
        r[di]--;
        c[dj]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) assert(x[i] == S);
    for (int i = 0; i < m; i++) assert(y[i] == S);

    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
