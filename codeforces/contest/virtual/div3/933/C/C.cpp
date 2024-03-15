#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') {
            if ((i - 2 >= 0 && s[i - 2] == 'm' && s[i - 1] == 'a') || (i + 2 < n && s[i + 1] == 'i' && s[i + 2] == 'e'))ans++;
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