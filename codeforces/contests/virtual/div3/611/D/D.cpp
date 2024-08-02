#include <bits/stdc++.h>
#define int long long
using namespace std;

struct info {
    int r;
    int p;
    int c;
    bool operator<(const info& other) const {
        return c < other.c;
    }
    bool operator>(const info& other) const {
        return c > other.c;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (auto& c : x) cin >> c;
    int j = m - 1;
    vector<int> y(m);
    int ans = 0;
    auto bfs = [&]() {
        priority_queue<info, vector<info>, greater<info>> pq;
        map<int, bool> vis;
        for (auto& c : x) {
            vis[c] = true;
            pq.push({ c, c - 1, 1 });
            pq.push({ c, c + 1, 1 });
        }
        while (j >= 0) {
            auto [r, p, c] = pq.top();
            pq.pop();
            if (vis[p]) continue;
            vis[p] = true;
            y[j--] = p;
            ans += c;
            if (p < r) {
                pq.push({ r, p - 1, c + 1 });
            }
            else {
                pq.push({ r, p + 1, c + 1 });
            }
        }
        };
    bfs();
    cout << ans << endl;
    for (auto& c : y) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*
#include <bits/stdc++.h>
using namespace std;

void solve() {
    cerr << "Solving" << endl;
    int n, m;
    cin >> n >> m;
    cerr << n << " " << m << endl;
    vector<int> x(n);
    for (auto& c : x) cin >> c;
    set<int> all(x.begin(), x.end());
    int j = m - 1;
    vector<int> y(m);
    int ans = 0;
    auto bfs = [&]() {
        queue<pair<int, int>> q;
        for (auto& c : x) q.push({ c, c });
        map<int, bool> vis;
        while (j >= 0) {
            auto [r, p] = q.front();
            q.pop();
            if (vis[p]) continue;
            vis[p] = true;
            int d = abs(r - p);
            if (d > 0) {
                y[j--] = p;
                ans += d;
            }
            for (int dx : {-1, 1}) {
                if (!vis[p + dx] && !all.count(p + dx)) {
                    q.push({ r, p + dx });
                }
            }
        }
        };
    cerr << "bfs" << endl;
    bfs();
    cout << ans << endl;
    for (auto& c : y) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/