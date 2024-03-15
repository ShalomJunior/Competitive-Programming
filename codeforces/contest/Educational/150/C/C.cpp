#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s; cin >> s;
    int n = size();
    vector<char> C(n);
    C[n - 1] = s[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        C[i] = max(C[i + 1], s[i + 1]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int add = pow(10, s[i] - 'A');
        if (s[i] < C[i]) add *= -1;
        sum += add;
    }
    for (int i = 0; i < n; i++) {

    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}