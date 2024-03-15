#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> f(n);
    vector<int> cnt(n);
    bool good = true;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        cnt[a]++, cnt[b]++;
        good &= (a != b && cnt[a] <= 2 && cnt[b] <= 2);
        f[a].push_back(b);
        f[b].push_back(a);
    }
    if (!good) { cout << "NO" << endl; return; }
    vector<bool> da(n + 1), db(n + 1);
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        da[tp] = true; db[tp] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}