#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;
    char a[n][m];
    char match[n][m];
    vector<pair<int, int>> idx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            match[i][j] = '?';
            cin >> a[i][j];
            if (a[i][j] == '0')idx.push_back({ i, j });
            if (x1 <= i && i <= x2 && y1 <= j && j <= y2)match[i][j] = '0';
        }
    }
    for (auto& [k, l] : idx) {
        for (int dk : {-1, 0, 1}) {
            for (int dl : {-1, 0, 1}) {
                int n_k = k + dk;
                int n_l = l + dl;
                if (n_k < 0 || n_k >= n || n_l < 0 || n_l >= m) {
                    continue;
                }
                if (n_k == k && n_l == l)continue;
                match[n_k][n_l] = '0';
            }
        }
    }
    vector<pair<int, int>> bad;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (match[i][j] != '0') {
                if (x1 - 1 <= i && i <= x2 + 1 && y1 - 1 <= j && j <= y2 + 1) {
                    bad.push_back({ i, j });
                }
            }
        }
    }
    int z = bad.size();
    assert(z <= 20);
    vector<vector<int>> cnt(n, vector<int>(m));
    for (int i = 0; i < (1 << z); i++) {
        for (int j = 0; j < z; j++) {
            match[bad[j].first][bad[j].second] = (i & (1 << j) ? '1' : '0');
        }
        bool flag = true;
        for (int k = x1; flag && k <= x2; k++) {
            for (int l = y1; flag && l <= y2; l++) {
                int o = 0;
                for (int dk : {-1, 0, 1}) {
                    for (int dl : {-1, 0, 1}) {
                        int n_k = k + dk;
                        int n_l = l + dl;
                        if (n_k < 0 || n_k >= n || n_l < 0 || n_l >= m) {
                            continue;
                        }
                        if (n_k == k && n_l == l) continue;
                        if (match[n_k][n_l] == '1')o++;
                    }
                }
                char dig = '0' + o;
                assert('0' <= dig && dig <= '9');
                assert(a[k][l] != '?');
                if (a[k][l] != '?' && a[k][l] != dig) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    if (x1 - 1 <= k && k <= x2 + 1 && y1 - 1 <= l && l <= y2 + 1) {
                        if (match[k][l] == '1')cnt[k][l]++;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (x1 - 1 <= i && i <= x2 + 1 && y1 - 1 <= j && j <= y2 + 1) {
                if (x1 <= i && i <= x2 && y1 <= j && j <= y2) continue;
                ans += cnt[i][j] == 0;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

/*
int sq = x2 - x1 + 1;
    sq++;
    int c = n * m;
    char match[sq][sq];
    cout << "here" << endl;
    for (int i = 0; i < (1 << sq); i++) {
        for (int j = 0; j < sq; j++) {
            match[j / m][j % m] = (i & (1 << j) ? '1' : '0');
        }
        bool flag = true;
        for (int k = 0; flag && k < n; k++) {
            for (int l = 0; flag && l < m; l++) {
                int o = 0;
                for (int dk : {-1, 0, 1}) {
                    for (int dl : {-1, 0, 1}) {
                        int n_k = k + dk;
                        int n_l = l + dl;
                        if (n_k < 0 || n_k >= m || n_l < 0 || n_l >= m) {
                            continue;
                        }
                        if (match[n_k][n_l] == '1')o++;
                    }
                }
                if (match[k][l] == '1')o--;
                char dig = '0' + o;
                if (a[k][l] != '?' && a[k][l] != dig) {
                    flag = false;
                    break;
                }
            }
        }
        for (int k = x1 - 1; k <= x2 + 1; k++) {
            for (int l = y1 - 1; l <= y2 + 1; l++) {
                if (k < 0 || k >= sq || l < 0 || l >= sq)continue;
                int x = k - (x1 - 1);
                int y = l - (y1 - 1);

            }
        }
    }
    for (int i = 0; i < (1 << c); i++) {
        cout << "i = " << i << endl;
        for (int j = 0; j < c; j++) {
            match[j / m][j % m] = (i & (1 << j) ? '1' : '0');
        }
        bool flag = true;
        for (int k = 0; flag && k < n; k++) {
            for (int l = 0; flag && l < m; l++) {
                int o = 0;
                for (int dk : {-1, 0, 1}) {
                    for (int dl : {-1, 0, 1}) {
                        int n_k = k + dk;
                        int n_l = l + dl;
                        if (n_k < 0 || n_k >= m || n_l < 0 || n_l >= m) {
                            continue;
                        }
                        if (match[n_k][n_l] == '1')o++;
                    }
                }
                if (match[k][l] == '1')o--;
                char dig = '0' + o;
                if (a[k][l] != '?' && a[k][l] != dig) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    if (x1 <= k && k <= x2 && y1 <= l && l <= y2) continue;
                    if (match[k][l] == '1')cnt[k][l]++;
                }
            }
        }
    }

*/


/*
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    vector<string> mp(n);
    for (auto& e : mp) cin >> e;

    int cx = x2 - x1 + 1;
    int cy = y2 - y1 + 1;
    int val = 2 * (cx + cy) + 8;
    if (x1 == 0) val -= cx;
    if (x2 == n - 1) val -= cx;
    if (y1 == 0) val -= cy;
    if (y2 == m - 1) val -= cy;
    auto check = [&](int t) -> bool {
        bool ok = true;
        vector<string> mp2 = mp;
        int at = 0;
        for (int x = max(x1 - 1, 0); x <= min(x2 + 1, n - 1); x++) {
            for (int y = max(y1 - 1, 0); y <= min(y2 + 1, m - 1); y++) {
                if (x != x1 - 1 && x != x2 + 1 && y != y1 - 1 && y != y2 + 1)continue;
                if (t & (1ll << at)) {
                    mp2[x][y] = '*';
                }
                at++;
            }
        }

        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                int sum = 0;
                for (auto i : { -1, 0, 1 }) {
                    for (auto j : { -1, 0, 1 }) {
                        int nx = x + i, ny = y + j;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (mp2[nx][ny] == '*') sum++;
                        }
                    }
                }
                ok &= sum == (int)(mp2[x][y] - '0');

            }
        }

        if (ok) {
            // cout <<"t ---> " << bitset<16>(t).to_string() <<endl;
            // for(auto e : mp2) cout << e << endl;
        }
        return ok;

        };

    int ans = 0;
    for (int t = 0; t < (1ll << val); t++) {
        if (check(t)) ans |= t;
    }
    cout << val - __builtin_popcount(ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

*/