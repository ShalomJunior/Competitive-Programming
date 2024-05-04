#include <bits/stdc++.h>
#define pb push_back
using namespace std;

char f(char c) { return 'a' + c - '1'; }

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (n < 3) {
        string ans = "";
        for (auto& c : s)ans.pb(f(c));
        cout << ans << endl;
        return;
    }

    string ans = "";
    int i;
    for (i = n - 1; i > 1; i--) {
        string t = s.substr(i - 2, 3);
        if (s[i] != '0') {
            ans.pb(f(s[i]));
        }
        else {
            int add = 10 * (s[i - 2] - '0') + (s[i - 1] - '0');
            ans.pb('a' + add - 1);
            i -= 2;
        }
    }

    for (; i >= 0; i--) {
        ans.pb(f(s[i]));
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}