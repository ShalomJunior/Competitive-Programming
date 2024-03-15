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

int compress(vector<int>& a) {
    auto t = a;
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    for (auto& c : a) {
        c = lower_bound(t.begin(), t.end(), c) - t.begin() + 1;
    }
    return t.size();
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int m = compress(a);
    long long ans = 0;
    fenwick<int> fen(m);
    fen.add(a[0], 1);
    for (int i = 1; i < n; i++) {
        int less = fen.query(a[i] - 1);
        int great = i - fen.query(a[i]);
        ans += min(less, great);
        fen.add(a[i], 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
