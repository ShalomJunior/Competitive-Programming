#include<bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
class sum {
public:
    int n;
    vector<T> pref;
    sum(vector<T>& arr) {
        n = arr.size();
        pref.resize(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    T query(int l, int r) {
        assert(l >= 0 && r < n);
        return pref[r] - (l ? pref[l - 1] : 0);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sum x(a);
    sum y(b);
    auto check = [&](int mid) {
        int r = (n + mid) / 4;
        int m = (n + mid) - r;
        int f = m <= mid ? mid * 100 : mid * 100 + x.query(n - (m - mid), n - 1);
        int g = m <= n ? y.query(n - m, n - 1) : y.query(0, n - 1);
        return f >= g;
        };
    int L = 0, R = 1e6;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}

