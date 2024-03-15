#include <bits/stdc++.h>
#define int long long
using namespace std;

int g(string s) {
    int len = s.length();
    vector<int> a(len);
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') continue;
        bool flag = false;
        int sum = -1;
        for (int j = i - 1; j >= 0; j--) {
            a[j] == 1 ? sum++ : sum--;
            if (sum > 0) {
                flag = true;
                break;
            }
        }
        if (!flag)a[i] = 1;
    }
    int x = count(s.begin(), s.end(), '1');
    int y = count(a.begin(), a.end(), 1);
    cout << s << " " << x << " -> " << y << endl;
    assert(y <= x);
    return y;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string p = s.substr(i, j - i + 1);
            ans += g(p);
        }
    }
    cout << ans << endl << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}