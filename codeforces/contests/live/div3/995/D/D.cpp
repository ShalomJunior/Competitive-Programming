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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int s = accumulate(a.begin(), a.end(), 0LL);
    auto b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int ans = 0;
    fenwick<int> fen(n);
    for (int j = 0; j < n; j++) {
        int r = s - a[j];
        int l1 = r - x;
        int l2 = r - y;
        if (l1 < l2) continue;
        int L = max(0LL, l2);
        int R = max(0LL, l1);
        if (L > R) continue;
        int f = lower_bound(b.begin(), b.end(), L) - b.begin() + 1;
        int g = upper_bound(b.begin(), b.end(), R) - b.begin();
        ans += fen.rangeQuery(f, g);
        int i = lower_bound(b.begin(), b.end(), a[j]) - b.begin() + 1;
        fen.add(i, 1);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
