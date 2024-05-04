#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int ans = 0;
    int last = s[0], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == last) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 1;
            last = s[i];
        }
    }
    cout << max(ans, cnt) + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

