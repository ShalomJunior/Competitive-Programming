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
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    fenwick<int> fen(n);
    set<int> id;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fen.add(i, a[i]);
        if (a[i] == 1) id.insert(i);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s; cin >> s;
            int tot = fen.query(n);
            if (tot < s) {
                cout << "NO" << endl;
                continue;
            }
            if (id.empty()) {
                cout << (tot % 2 == s % 2 ? "YES" : "NO") << endl;
            }
            else {
                int l = *id.begin();
                int r = *prev(id.end());
                int totL = fen.rangeQuery(l, n);
                int totR = fen.rangeQuery(1, r);
                if (totL >= s || totR >= s) {
                    cout << "YES" << endl;
                }
                else {
                    cout << (fen.rangeQuery(l, r) % 2 == s % 2 ? "YES" : "NO") << endl;
                }
            }
        }
        else {
            int i, v; cin >> i >> v;
            fen.add(i, v - a[i]);
            a[i] = v;
            if (v == 2) id.erase(i);
            else id.insert(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}