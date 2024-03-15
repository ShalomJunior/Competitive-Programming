#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int n, m;

void solve() {
    vector<pair<int, int>> guards(n);
    priority_queue<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        a.push({ -s, e });
    }
    vector<pair<int, int>> spies(m);
    for (int i = 0; i < m; i++) {
        cin >> spies[i].F;
        spies[i].S = i;
    }
    sort(spies.begin(), spies.end());
    priority_queue<int> q;
    vector<int> ans(m);
    for (int i = 0; i < m;i++) {
        if (i && spies[i].F == spies[i - 1].F) {
            ans[spies[i].S] = ans[spies[i - 1].S];
            continue;
        }
        while (!a.empty() && -a.top().F <= spies[i].F) {
            q.push(-a.top().S); a.pop();
        }
        while (!q.empty() && -q.top() < spies[i].F) {
            q.pop();
        }
        ans[spies[i].S] = (int)q.size();
    }
    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

int main() {
    while (cin >> n >> m, n & m)
        solve();
}