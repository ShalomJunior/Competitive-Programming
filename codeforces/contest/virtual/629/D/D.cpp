#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;  cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int color = 1, cnt = 1;
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) ans[i] = ans[i - 1];
        else {
            if (color > 1) ans[i] = --color;
            else {
                color++;
                ans[i] = color;
                cnt = max(cnt, color);
            }
        }
    }
    if (a[0] != a[n - 1] && ans[0] == ans[n - 1]) {
        for (int i = 1; i <= cnt + 1; i++) {
            if (a[n - 2] == a[n - 1]) {
                if (ans[0] != i) {
                    ans[n - 1] = i;
                    cnt = max(cnt, i);
                    break;
                }
            }
            else {
                if (ans[n - 2] != i && ans[0] != i) {
                    ans[n - 1] = i;
                    cnt = max(cnt, i);
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}