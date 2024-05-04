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
    int n, q;
    cin >> n >> q;
    map<int, int> r;
    map<int, int> c;
    fenwick<int> rows(n);
    fenwick<int> cols(n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            if (!r.count(x)) rows.add(x, 1);
            if (!c.count(y)) cols.add(y, 1);
            r[x]++;
            c[y]++;
        }
        else if (t == 2) {
            int x, y;
            cin >> x >> y;
            r[x]--;
            c[y]--;
            if (r[x] == 0) {
                r.erase(x);
                rows.add(x, -1);
            }
            if (c[y] == 0) {
                c.erase(y);
                cols.add(y, -1);
            }
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << (rows.rangeQuery(x1, x2) == (x2 - x1 + 1) || cols.rangeQuery(y1, y2) == (y2 - y1 + 1) ? "Yes" : "No") << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}