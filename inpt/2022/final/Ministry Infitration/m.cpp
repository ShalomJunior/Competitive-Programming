#include <bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define mp make_pair
#define f first
#define s second

using namespace std;

void solve(int n, int m) {
    priority_queue<pr> pq, sec;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        sec.push(mp(-a, b));
    }

    vector<int> come(m);
    unordered_map<int, vector<int>> um;
    for (int i = 0; i < m; i++) {
        cin >> come[i];
        um[come[i]].push_back(i);
    }
    sort(come.begin(), come.end());

    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int t = come[i];
        if (i && come[i] == come[i - 1]) continue;

        while (!sec.empty() && -sec.top().f <= t) {
            auto in = sec.top();
            pq.push(mp(-in.s, -in.f));
            sec.pop();
        }

        while (!pq.empty() && -pq.top().f < t) {
            pq.pop();
        }

        for (auto& p : um[t]) {
            ans[p] = (int)pq.size();
        }
    }
    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    while (n || m) {
        solve(n, m);
        cin >> n >> m;
    }
}