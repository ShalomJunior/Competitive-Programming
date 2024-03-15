#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    int cnt = 0;
    for (auto& c : a) {
        cin >> c;
        cnt += count(c.begin(), c.end(), '1');
    }
    auto go = [&](int x, int y, int len) {
        int ans = 0;
        for (int i = x; i < x + len; i++) {
            for (int j = y; j < y + len; j++) {
                if (i >= n || y >= n || a[i][j] == '0') return false;
                ans++;
            }
        }
        return ans == cnt;
        };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 1; k <= n - j; k++) {
                if (go(i, j, k)) {
                    cout << "SQUARE" << endl;
                    return;
                }
            }
        }
    }
    cout << "TRIANGLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}