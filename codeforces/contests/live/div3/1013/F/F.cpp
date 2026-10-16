#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < (int)arr.size(); index += (index & (-index))) {
            arr[index] += val;
            arr[index] %= MOD;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
            sum %= MOD;
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        int res = query(right) - query(left - 1);
        return (res + MOD) % MOD;
    }
};

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<fenwick<int>> X(n + 1, fenwick<int>(m + 1));
    vector<fenwick<int>> Y(n + 1, fenwick<int>(m + 1));
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') continue;
            int l = j - d + 1;
            int r = j + d - 1;
            l = max(l, 1LL);
            r = min(r, m);
            if (i < n) {
                X[i].add(j, X[i + 1].rangeQuery(l, r));
                X[i].add(j, Y[i + 1].rangeQuery(l, r));
            }
            else {
                X[i].add(j, 1);
            }
        }
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') continue;
            int l = j - d;
            int r = j + d;
            l = max(l, 1LL);
            r = min(r, m);
            Y[i].add(j, X[i].rangeQuery(l, r) - X[i].rangeQuery(j, j));
        }
    }
    int ans = X[1].rangeQuery(1, m) + Y[1].rangeQuery(1, m);
    cout << ans % MOD << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


/*


#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < (int)arr.size(); index += (index & (-index))) {
            arr[index] += val;
            arr[index] %= MOD;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
            sum %= MOD;
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<fenwick<int>> X(n + 1, fenwick<int>(m + 1));
    vector<fenwick<int>> Y(n + 1, fenwick<int>(m + 1));
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') continue;
            int l = j - d + 1;
            int r = j + d - 1;
            l = max(l, 1LL);
            r = min(r, m);
            if (i < n) {
                X[i].add(j, X[i + 1].rangeQuery(l, r));
                X[i].add(j, Y[i + 1].rangeQuery(l, r));
            }
            else {
                X[i].add(j, 1);
            }
        }
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') continue;
            int l = j - d;
            int r = j + d;
            l = max(l, 1LL);
            r = min(r, m);
            Y[i].add(j, X[i].rangeQuery(l, r) - X[i].rangeQuery(j, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << i << " ]@ " << j << endl;
            cout << X[i].rangeQuery(j, j) << " -> ";
            cout << Y[i].rangeQuery(j, j) << " ";
            cout << endl;
        }
    }
    int ans = X[1].rangeQuery(1, m) + Y[1].rangeQuery(1, m);
    cout << ans % MOD << endl;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
*/