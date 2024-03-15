#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<Mine> vec(n);
    for (auto& [f, s] : vec) {
        cin >> f >> s;
        --f, --s;
    }
    if (n == 3) {
        cout << "1 2 3\n";
        return;
    }
    vector<int> next(n, -1);
    for (int i = 0; i < n; i++) {
        int f = vec[i].F, s = vec[i].S;
        if (vec[f].F == s || vec[f].S == s) next[f] = s;
        else next[s] = f;
    }
    vector<int> ans(n);
    vector<bool> vis(n);
    int id = 0;
    do {
        cout << id + 1 << " ";
        vis[id] = true;
        id = next[id];
    } while (!vis[id]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}