#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int n, int d) {
    string s = to_string(n);
    int len = s.length();
    if (!d)return max(len - 1, 1LL);
    string comp(len, '0' + d);
    stringstream ss; ss << comp;
    int m; ss >> m;
    return (m <= n) ? len : len - 1;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < 10; i++) {
        cout << f(n, i) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}