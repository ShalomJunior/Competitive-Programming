#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int s = 0;
    string ans;
    for (int i = 0; s < n; i++) {
        int add = i & 1 ? 1 : 2;
        ans += i & 1 ? '1' : '2';
        s += add;
        if (s == n) {
            cout << ans << endl;
            return;
        }
    }
    cout << ans.substr(1, ans.size() - 1) << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}