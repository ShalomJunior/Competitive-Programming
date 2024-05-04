#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> neb(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        neb[a].push_back(b);
        neb[b].push_back(a);
    }
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        a.insert(i);
        b.insert(i);
    }
    bool who = true;
    queue<int> q; q.push(0); q.push(neb[0][0]);
    while (a.size() < n || b.size() < n) {
        int f = q.front(); q.pop();
        int s = q.front(); q.pop();
        if (who) {

        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}