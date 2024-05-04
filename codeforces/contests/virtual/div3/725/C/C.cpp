#include <bits/stdc++.h>
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
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int m = b.size();
    fenwick<int> fen(m);
    for (auto& c : a) {
        int j = lower_bound(b.begin(), b.end(), c) - b.begin() + 1;
        fen.add(j, 1);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        fen.add(j, -1);
        auto f = lower_bound(b.begin(), b.end(), l - a[i]);
        auto s = upper_bound(b.begin(), b.end(), r - a[i]); --s;
        int m = f - b.begin() + 1;
        int M = s - b.begin() + 1; ;
        ans += fen.rangeQuery(m, M);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}