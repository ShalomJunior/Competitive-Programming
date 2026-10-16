#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int a, b;
    cin >> a >> b;
    vector<int> power(n, 1);
    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * 10) % b;
    }
    vector<int> l(n);
    for (int i = 0, x = 0; i < n; i++) {
        x = (x * 10 + s[i] - '0') % a;
        l[i] = x;
    }
    vector<int> r(n);
    for (int i = 0, x = 0; i < n; i++) {
        x = (x * 10 + s[i] - '0') % b;
        r[i] = x;
    }
    for (int i = 0; i < n - 1; i++) {
        if (l[i] == 0) {
            int rem = (r[n - 1] - r[i] * power[n - i - 1] % b);
            rem = (rem + b) % b;
            if (rem == 0 && s[i + 1] != '0') {
                cout << "YES" << endl;
                cout << s.substr(0, i + 1) << endl;
                cout << s.substr(i + 1, n - i - 1) << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
