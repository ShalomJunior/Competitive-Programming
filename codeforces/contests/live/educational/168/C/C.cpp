#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') tot++;
        else if (s[i] == ')') tot--;
        else {
            s[i] = '(';
            tot++;
        }
    }
    int close = tot / 2;
    int pref = 0;
    for (int i = 0; i < n; i++) {
        pref += (s[i] == '(' ? 1 : -1);
        if (i % 2 == 0 && pref >= 2 && close) {
            s[i] = ')';
            close--;
            pref -= 2;
        }
    }
    int ans = 0;
    vector<int> open;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') open.push_back(i);
        else {
            ans += i - open.back();
            open.pop_back();
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
