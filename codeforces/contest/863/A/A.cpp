#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; char d; cin >> n >> d;
    string s; cin >> s;

    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] < d) {
            ans = s.substr(0, i);
            ans.push_back(d);
            if (i < n)ans += s.substr(i, n);
            cout << ans << endl;
            return;
        }
    }
    s.push_back(d);
    cout << s << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}