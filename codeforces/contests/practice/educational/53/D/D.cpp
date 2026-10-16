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
    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1);
    fenwick<int> fen(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fen.add(i, a[i]);
    }
    int k = n;
    int ans = 0;
    auto check = [&](int mid) {
        return fen.query(mid) > t;
        };
    while (t) {
        int L = 1, R = n + 1;
        while (L < R) {
            int mid = (L + R) / 2;
            check(mid) ? R = mid : L = mid + 1;
        }
        if (L == R && R <= n) {
            k--;
            fen.add(R, -a[R]);
        }
        int tot = fen.query(n);
        if (tot == 0) break;
        ans += k * (t / tot);
        t %= tot;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
