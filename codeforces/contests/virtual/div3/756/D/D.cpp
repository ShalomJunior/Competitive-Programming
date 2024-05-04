#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> order(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        int u; cin >> u;
        u--;
        order[i] = u;
        pos[u] = i;
    }
    for (int i = 0; i < n; i++) {
        if (pos[i] < pos[p[i]]) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> w(n);
    vector<int> dis(n);
    int D = 1;
    for (int i = 1; i < n; i++) {
        w[order[i]] = max(D - dis[p[order[i]]], 0);
        dis[order[i]] = dis[p[order[i]]] + w[order[i]];
        D = dis[order[i]] + 1;
    }
    for (auto& c : w)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}