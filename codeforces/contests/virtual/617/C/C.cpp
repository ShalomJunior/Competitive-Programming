#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; string s;
    cin >> n >> s;
    int x = 0, y = 0;
    map<pair<int, int>, vector<int>> h;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') x--;
        else if (s[i] == 'R') x++;
        else if (s[i] == 'U') y++;
        else y--;
        a[i] = { x, y };
        h[a[i]].push_back(i);
    }
    int ans = INF, l, r;
    if (h[{0, 0}].size()) {
        ans = h[{0, 0}][0];
        l = 0, r = ans;
    }
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(h[a[i]].begin(), h[a[i]].end(), i);
        if (it != h[a[i]].end()) {
            if (*it - i < ans) {
                l = i + 1, r = *it;
                ans = *it - i;
            }
        }
    }
    if (ans == INF) cout << -1;
    else cout << l + 1 << " " << r + 1;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}