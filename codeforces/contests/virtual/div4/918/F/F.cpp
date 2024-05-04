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
    vector<int> a(n), b(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        x.push_back(a[i]);
        x.push_back(b[i]);
    }
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(x.begin(), x.end(), a[i]) - x.begin() + 1;
        b[i] = lower_bound(x.begin(), x.end(), b[i]) - x.begin() + 1;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        if (a[i] != a[j]) return a[i] < a[j];
        return b[i] < b[j];
        });
    int m = x.size();
    fenwick<int> fen(m);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int id = p[i];
        ans += (i - fen.query(b[id] - 1));
        fen.add(b[id], 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}