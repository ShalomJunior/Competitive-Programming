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
    vector<pair<int, int>> x(n);
    vector<int> c;
    for (auto& [f, s] : x) {
        cin >> f >> s;
        c.push_back(f); c.push_back(s);
    }
    sort(x.begin(), x.end());
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = x[i].first;
        b[i] = x[i].second;
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    reverse(c.begin(), c.end());
    int m = c.size();
    map<int, int> h;
    for (int i = 0; i < m; i++) {
        h[c[i]] = i + 1;
    }
    int cnt = 0;
    fenwick<int> fen(m);
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        int curr = it - (a.begin() + i) - 1;
        curr += fen.query(h[a[i]]);
        fen.add(h[b[i]], 1);
        cnt = max(cnt, curr);
    }
    cout << n - 1 - cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}