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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    auto ax = a;
    auto bx = b;
    sort(ax.begin(), ax.end());
    sort(bx.begin(), bx.end());
    if (ax != bx) {
        cout << "NO" << endl;
        return;
    }
    int M = ax.back();
    int cnt_x = 0;
    int cnt_y = 0;
    fenwick<int> x(M);
    fenwick<int> y(M);
    for (int i = 0; i < n; i++) {
        cnt_x += x.rangeQuery(a[i] + 1, M);
        cnt_y += y.rangeQuery(b[i] + 1, M);
        x.add(a[i], 1);
        y.add(b[i], 1);
    }
    cout << (cnt_x % 2 == cnt_y % 2 ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
