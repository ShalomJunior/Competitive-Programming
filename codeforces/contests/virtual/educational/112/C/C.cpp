#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] += val;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void solve() {
    int m;
    cin >> m;
    vector<int> a(m + 1);
    fenwick<int> x(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        x.add(i, a[i]);
    }
    vector<int> b(m + 1);
    fenwick<int> y(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        y.add(i, b[i]);
    }
    int ans = INF;
    for (int i = 1; i <= m; i++) {
        int s = max(i + 1 <= m ? x.rangeQuery(i + 1, m) : 0LL, y.query(i - 1));
        ans = min(ans, s);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
