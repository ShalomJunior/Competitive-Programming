#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (!flag) {
                flag = true;
            }
            else break;
        }
        else {
            ans += s[i] == '@';
            flag = false;
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
