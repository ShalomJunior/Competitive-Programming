#include <bits/stdc++.h>
using namespace std;

void normalize(string& s, int& n) {
    int j = 0;
    while (j < n && s[j] == '0') j++;
    s = j == n ? "" : s.substr(j, n - j);
    n = s.size();
}

string get(string s, string p) {
    int n = s.size();
    int m = p.size();
    p = string(n - m, '0') + p;
    string ans;
    for (int i = 0; i < n; i++) {
        ans += s[i] == '1' || p[i] == '1' ? '1' : '0';
    }
    return ans;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    normalize(s, n);
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    if (count(s.begin(), s.end(), '1') == n) {
        cout << s << endl;
        return;
    }
    int j = 0;
    while (s[j] == '1') j++;
    int len = n - j;
    string ans;
    for (int i = 0; i + len - 1 < n; i++) {
        auto res = get(s, s.substr(i, len));
        if (res > ans) ans = res;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
