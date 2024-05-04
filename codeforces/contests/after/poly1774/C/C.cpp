#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int zero = 0, one = 0;
    for (int i = 2; i <= n; i++) {
        s[i - 2] == '0' ? zero++ : one++;
        int l = one + 1, r = i - zero + 1;
        cout << l << "#" << r << endl;
        cout << r - l + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}