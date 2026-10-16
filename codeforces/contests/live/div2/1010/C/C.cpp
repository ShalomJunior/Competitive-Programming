#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    bool flag = false;
    for (int i = 0, m = 1; i < n; i++) {
        if (m >= k) {
            flag = true;
            break;
        }
        m *= 2;
    }
    if (!flag) {
        cout << -1 << endl;
        return;
    }
    auto check = [&](int z) {
        for (int i = 0, m = 1; i <= z; i++) {
            if (k <= m) return true;
            m *= 2;
        }
        return false;
        };
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    deque<int> l;
    deque<int> r;
    for (int i = 0, m = 1; i < n; i++) {
        if (m * 2 <= k) m *= 2;
        int next = q.front();
        q.pop();
        if (check(n - 1 - next)) {
            l.push_back(next);
            continue;
        }
        int cnt = pow(2, n - next - 1);
        if (k <= cnt) {
            l.push_back(next);
        }
        else {
            k -= cnt;
            r.push_front(next);
        }
    }
    for (auto& c : l) cout << c << " ";
    for (auto& c : r) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


/*


    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    map<int, vector<vector<int>>> mp;
    do {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int mn = n;
            for (int j = i; j < n; j++) {
                mn = min(mn, p[j]);
                cnt += mn;
            }
        }
        mp[cnt].push_back(p);
    } while (next_permutation(p.begin(), p.end()));
    for (auto& v : prev(mp.end())->second) {
        for (auto& c : v) cerr << c << " ";
        cerr << endl;
    }*/