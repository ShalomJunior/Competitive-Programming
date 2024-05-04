#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int ans = 0, k = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == '*') {
            ans += i - j;
            k++; j++;
        }
    }
    int l = s[0] == '*' ? 1 : 0;
    int r = k - l;
    cout << "ans = " << ans << endl;
    int x = ans;
    for (int i = 1; i <= n - k; i++) {
        x += l - r;
        ans = min(ans, x);
        if (s[i] == '*') l++, r--;
        cout << "ans " << i << " " << ans << endl;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}