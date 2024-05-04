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
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int m = b.size();
    fenwick<int> o(m), e(m);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        int cnt = (a[i] & 1 ? o.rangeQuery(j + 1, m) : e.rangeQuery(j + 1, m));
        if (cnt) {
            cout << "NO" << endl;
            return;
        }
        a[i] & 1 ? o.add(j, 1) : e.add(j, 1);
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}