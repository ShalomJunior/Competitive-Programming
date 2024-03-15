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
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    int ans = 0;
    fenwick<int> fen(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        int cnt = fen.query(p[i]);
        auto it = s.lower_bound(p[i]);
        if (it != s.begin() && !cnt) ans++;
        if (it != s.begin()) {
            fen.add(p[i], 1);
        }
        s.insert(p[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}