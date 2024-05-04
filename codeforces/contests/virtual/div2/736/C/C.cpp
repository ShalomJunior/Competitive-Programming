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
    int n, m; cin >> n >> m;
    vector<set<int>> links(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        links[u].insert(v);
        links[v].insert(u);
    }
    fenwick<int> fen(n);
    for (int i = 1; i <= n; i++) {
        if (links[i].empty()) continue;
        if (i < *links[i].begin()) {
            fen.add(i, 1);
        }
    }
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1 || t == 2) {
            int u, v;
            cin >> u >> v;
            if (t == 1) {
                links[u].insert(v);
                links[v].insert(u);
            }
            else {
                links[u].erase(v);
                links[v].erase(u);
            }
            int du = u < *links[u].begin();
            int dv = v < *links[v].begin();
            fen.add(u, du - fen.rangeQuery(u, u));
            fen.add(v, dv - fen.rangeQuery(v, v));
        }
        else {
            cout << fen.query(n) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}