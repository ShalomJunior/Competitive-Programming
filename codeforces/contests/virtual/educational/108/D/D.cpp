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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    fenwick<int> fen(n + 1);
    for (int i = 0; i < n; i++) {
        fen.add(i + 1, a[i] * b[i]);
    }
    int ans = fen.query(n + 1);
    auto go = [&](int l, int r) {
        int curr = 0;
        while (l >= 0 && r < n) {
            curr += a[l] * b[r] + (l == r ? 0 : a[r] * b[l]);
            int x = fen.rangeQuery(1, l) + curr + fen.rangeQuery(r + 2, n);
            ans = max(ans, x);
            l--; r++;
        }
        };
    for (int i = 0; i < n; i++) go(i, i), go(i, i + 1);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
