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

struct Point {
    int x;
    int y;
    int id;
    bool operator<(const Point& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Point> a(n);
    vector<int> y;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = { x2, y2, i };
        y.push_back(y2);
    }
    int q;
    cin >> q;
    vector<Point> Q(q);
    for (int i = 0; i < q; i++) {
        int X, Y;
        cin >> X >> Y;
        Q[i] = { X, Y, i };
        y.push_back(Y);
    }
    sort(a.begin(), a.end());
    sort(Q.begin(), Q.end());
    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    int j = 0;
    fenwick<int> fen(y.size());
    vector<int> ans(q);
    for (auto& [X, Y, i] : Q) {
        while (j < n && a[j].x <= X) {
            int k = lower_bound(y.begin(), y.end(), a[j].y) - y.begin() + 1;
            fen.add(k, 1);
            j++;
        }
        int k = lower_bound(y.begin(), y.end(), Y) - y.begin() + 1;
        ans[i] = fen.query(k);
    }
    for (auto& c : ans) cout << c << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
