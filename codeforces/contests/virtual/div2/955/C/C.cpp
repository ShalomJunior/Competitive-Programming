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
            arr[index] = max(arr[index], val);
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum = max(sum, arr[index]);
        }
        return sum;
    }
};

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    fenwick<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(pref.begin() + 1, pref.end(), pref[i - 1] + l);
        if (it == pref.end() || *it - pref[i - 1] > r) continue;
        int j = it - pref.begin();
        dp.add(j, dp.query(i - 1) + 1);
    }
    cout << dp.query(n) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}