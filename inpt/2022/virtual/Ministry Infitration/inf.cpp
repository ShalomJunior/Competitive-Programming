#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
using namespace std;

void solve(int n, int m) {
    priority_queue<pair<int, int>> pq, sec;

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
        if (come[i] == come[i - 1])continue;
        int t = come[i];
        while (!sec.empty() && -sec.top().F <= t) {
            auto in = sec.top(); sec.pop();
            pq.push(mp(-in.S, -in.F));
        }

        while (!pq.empty() && -pq.top().F < t) {
            pq.pop();
        }
        for (auto idx : um[t]) {
            ans[idx] = (int)pq.size();
        }
    }

    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m, n || m)
        solve(n, m);
}