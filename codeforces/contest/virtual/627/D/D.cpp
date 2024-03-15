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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = b[i] - a[i];
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    int m = c.size();
    vector<int> h(n);
    fenwick<int> fen(m);
    for (int i = 0; i < n; i++) {
        h[i] = lower_bound(c.begin(), c.end(), b[i] - a[i]) - c.begin() + 1;
        fen.add(h[i], 1);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        fen.add(h[i], -1);
        int j = lower_bound(c.begin(), c.end(), a[i] - b[i]) - c.begin() + 1;
        ans += fen.query(j - 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}