#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

struct query {
    int t;
    int x, y;
};

void solve() {
    int q;
    cin >> q;
    vector<vector<int>> g(N);
    vector<query> a(q);
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x;
        if (t == 2) cin >> y;
        a[i] = { t, x, y };
        if (t == 2) {
            g[y].push_back(x);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
