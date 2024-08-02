#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 2) {
        cout << stoi(s) << endl;
        return;
    }
    int cnt = count(s.begin(), s.end(), '0');
    if (cnt > 0) {
        if (n == 3) {
            int x1 = stoi(s.substr(0, 2)) * (s.back() - '0');
            int x2 = stoi(s.substr(0, 2)) + (s.back() - '0');
            int y1 = (s[0] - '0') * stoi(s.substr(1, 2));
            int y2 = (s[0] - '0') + stoi(s.substr(1, 2));
            cout << min({ x1, x2, y1, y2 }) << endl;
        }
        else {
            cout << 0 << endl;
        }
        return;
    }
    int ans = 10000;
    for (int i = 0; i + 1 < n; i++) {
        int val = stoi(s.substr(i, 2));
        for (int j = 0; j < n; j++) {
            if (j == i || j == i + 1) continue;
            int d = s[j] - '0';
            if (d == 1) {}
            else {
                val += d;
            }
        }
        ans = min(ans, val);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
