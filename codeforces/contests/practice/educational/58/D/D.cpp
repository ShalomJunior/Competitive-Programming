#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
}

vector<int> dec(int n) {
    vector<int> d;
    for (auto& p : primes) {
        if (n < N && prime[n]) break;
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        if (cnt) d.push_back(p);
    }
    if (n > 1) d.push_back(n);
    return d;
}

struct Data {
    priority_queue<int, vector<int>, greater<int>> pq;
    void add(int x) {
        pq.push(x);
    }
    void normalize(int n) {
        while ((int)pq.size() > n) pq.pop();
    }
    int sum(int n) {
        int res = 0;
        while (n-- && !pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    vector<bool> vis(n);
    vector<map<int, int>> h(n);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        auto d = dec(a[r]);
        queue<int> q;
        map<int, Data> in;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                q.push(c);
                dfs(c);
                for (auto& p : d) {
                    in[p].add(h[c][p]);
                }
            }
            if (a[r] > 1) ans = max(ans, 1);
            for (auto& [k, v] : in) {
                cerr << r << " -> " << v.pq.size() << endl;
                v.normalize(2);
                h[r][k] = max(h[r][k], 1 + v.pq.top());
                ans = max(ans, v.sum(2));
            }
        }
        };
    dfs(0);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}