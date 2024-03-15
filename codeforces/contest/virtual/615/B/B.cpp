#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(N);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[y].push_back(x);
    }
    int last = 0, collect = 0;
    string path;
    for (int i = 0; i < N && collect != n; i++) {
        sort(a[i].begin(), a[i].end());
        for (auto& c : a[i]) {
            if (c >= last) {
                collect++;
                string add(c - last, 'R');
                path += add;
                path += 'C';
                last = c;
            }
        }
        path += 'U';
    }
    if (collect != n) { cout << "NO" << endl; return; }
    cout << "YES" << endl;
    string ans, t;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == 'C') {
            sort(t.begin(), t.end());
            ans += t;
            t = "";
        }
        else t += path[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}