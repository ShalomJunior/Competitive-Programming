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
    vector<int> a(n), x;
    fenwick<int> fen(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < i + 1) {
            x.push_back(i + 1);
            fen.add(i + 1, 1);
        }
    }
    int m = x.size();
    long long ans = 0;
    for (int j = m - 1; j > 0; j--) {
        fen.add(x[j], -1);
        ans += fen.query(a[x[j] - 1] - 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}