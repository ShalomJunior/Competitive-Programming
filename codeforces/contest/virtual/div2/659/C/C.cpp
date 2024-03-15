#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int ans = 0;
    while (true) {
        set<pair<char, char >> s;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                s.insert({ a[i], b[i] });
            }
        }
        if (s.empty())break;
        ans++;
        auto p = *s.begin();
        if (p.first >= p.second) {
            cout << -1 << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && a[i] == p.first) a[i] = p.second;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}