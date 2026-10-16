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
        for (; index < (int)arr.size(); index += (index & (-index))) {
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
    int n, x, k;
    cin >> n >> x >> k;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto& c : a) cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    b.push_back(INF);
    int m = b.size();
    int ans = 0;
    auto go = [&](vector<int> v) {
        fenwick<int> fen(m);
        for (int i = 0; i < n; i++) {
            int id = lower_bound(b.begin(), b.end(), v[i]) - b.begin() + 1;
            if (k == 0 && v[i] % x == 0) {}
            else {
                int rem = v[i] % x;
                int l = v[i] - k * x - rem + 1;
                int r = v[i] - max(k - 1, 0LL) * x - (k > 0 ? rem : 0);
                int f = lower_bound(b.begin(), b.end(), l) - b.begin() + 1;
                int g = upper_bound(b.begin(), b.end(), r) - b.begin();
                ans += fen.rangeQuery(f, g);
            }
            fen.add(id, 1);
        }
        };
    go(a);
    reverse(a.begin(), a.end());
    go(a);
    for (int i = 0; i < n; i++) {
        if (a[i] % x && k == 0) ans++;
        if (a[i] % x == 0 && k == 1) ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
