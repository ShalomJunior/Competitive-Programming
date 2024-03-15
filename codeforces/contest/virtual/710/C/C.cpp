#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    string a, b; cin >> a >> b;
    map<string, int> ha, hb;
    auto f = [&](map<string, int>& h, string& str) {
        int z = str.size();
        for (int i = 0; i < z; i++) {
            for (int j = 1; j <= z - i; j++) {
                string s = str.substr(i, j);
                h.count(s) ? h[s] = min(h[s], z - j) : h[s] = z - j;
            }
        }
        };
    f(ha, a), f(hb, b);
    int ans = INF;
    for (auto& [s, n] : ha) {
        if (!hb.count(s))continue;
        ans = min(ans, n + hb[s]);
    }
    cout << (ans == INF ? a.size() + b.size() : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}