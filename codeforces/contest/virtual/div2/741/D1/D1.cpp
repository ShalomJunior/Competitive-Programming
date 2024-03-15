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
    int n, q; string s;
    cin >> n >> q >> s;
    fenwick<int> fen(n);
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            s[i] == '-' ? fen.add(i + 1, 1) : fen.add(i + 1, -1);
        }
        else {
            s[i] == '+' ? fen.add(i + 1, 1) : fen.add(i + 1, -1);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int s = fen.rangeQuery(l, r);
        if (s == 0) cout << 0 << endl;
        else {
            s = abs(s);
            cout << (s & 1 ? 1 : 2) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

