#include <bits/stdc++.h>
#define int long long
using namespace std;

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    fenwick<int> fen(3 * n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fen.add(i, a[i]);
        fen.add(i + n, a[i]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int f1 = (l + n - 1) / n;
        int g1 = l % n ? l % n : n;
        int r1 = n - g1 + 1;
        int f2 = (r + n - 1) / n;
        int g2 = r % n ? r % n : n;
        int r2 = g2;
        int sum = 0;
        if (f1 == f2) {
            int j = f1 + g1 - 1;
            if (j > n) j -= n;
            sum += fen.rangeQuery(j, j + r - l);
        }
        else {
            int cnt = f2 - f1 - 1;
            sum += cnt * fen.rangeQuery(1, n);
            int j = f1 + g1 - 1;
            if (j > n) j -= n;
            sum += fen.rangeQuery(j, j + r1 - 1);
            sum += fen.rangeQuery(f2, f2 + r2 - 1);
        }
        cout << sum << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
