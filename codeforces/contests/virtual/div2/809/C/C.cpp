#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e15;
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
    int n; cin >> n;
    vector<int> h(n);
    for (auto& c : h) cin >> c;
    vector<int> a(n);
    for (int i = 1; i < n - 1; i++) {
        int mx = max(h[i - 1], h[i + 1]);
        a[i] = mx < h[i] ? 0 : mx - h[i] + 1;
    }
    fenwick<int> o(n / 2), e(n / 2);
    for (int i = 1; i < n - 1; i += 2) {
        o.add(1 + i / 2, a[i]);
        e.add(1 + i / 2, a[i + 1]);
    }
    int cnt = (n - 2 + 1) / 2;
    if (n & 1) {
        cout << o.query(cnt) << endl;
    }
    else {
        int ans = INF;
        for (int i = 0; i <= cnt; i++) {
            ans = min(ans, o.rangeQuery(1, i) + e.rangeQuery(i + 1, cnt));
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}