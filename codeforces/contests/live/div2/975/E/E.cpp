#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
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
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> D(n, 1);
    vector<int> M(n, -1);
    vector<bool> vis(n);
    function<void(int) > dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                D[c] = D[r] + 1;
                dfs(c);
                M[r] = max(M[r], M[c]);
            }
        }
        if (M[r] == -1) M[r] = D[r];
        };
    dfs(0);
    fenwick<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        x.add(D[i], 1);
        y.add(M[i], 1);
    }
    int d = *max_element(D.begin(), D.end());
    int ans = INF;
    for (int i = 1; i <= d; i++) {
        int need = 0;
        need += x.rangeQuery(i + 1, d);
        need += y.query(i - 1);
        ans = min(ans, need);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
