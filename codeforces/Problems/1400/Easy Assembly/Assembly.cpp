#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> all;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            v[i].push_back(a);
            all.push_back(a);
        }
    }
    sort(all.begin(), all.end());
    unordered_map<int, int> p;
    for (int i = 0; i < (int)all.size(); i++)
        p[all[i]] = i;

    int s = 0, c = 0, g = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < (int)v[i].size() - 1; j++) {
            if (p[v[i][j + 1]] != p[v[i][j]] + 1)t++;
        }
        s += t;
        g += (t + 1);
    }
    cout << s << " " << g - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}