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
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    vector<pair<int, int>> c = a, d = b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        x[i] = a[d[i].second].first;
        y[i] = b[c[i].second].first;
    }
    int ans1 = 0, ans2 = 0;
    fenwick<int> f(n), g(n);
    for (int i = 0; i < n; i++) {
        ans1 += f.query(x[i]);
        f.add(x[i], 1);
        ans2 += g.query(y[i]);
        g.add(y[i], 1);
    }
    if (ans1 < ans2) {
        for (auto& c : x) cout << c << " ";
        cout << endl;
        for (int i = 0; i < n; i++) cout << i + 1 << " ";
        cout << endl;
    }
    else {
        for (int i = 0; i < n; i++) cout << i + 1 << " ";
        cout << endl;
        for (auto& c : y) cout << c << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
