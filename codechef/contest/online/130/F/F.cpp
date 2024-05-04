#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
vector<int> choose(N);
void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<int> a(n + 1), b(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        a[i] = a[i + 1];
        b[i] = b[i + 1];
        if (s[i] == 'a') {
            a[i] += b[i + 1];
            a[i] %= MOD;
        }
        else {
            b[i] += 1 + a[i + 1];
            b[i] %= MOD;
        }
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            ans += 1LL * choose[cnt] * (b[i + 1] + 1) % MOD;
            ans %= MOD;
            cnt++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    choose[0] = 1;
    for (int i = 1; i < N; i++) {
        choose[i] = choose[i - 1] * 2 % MOD;
    }
    int t; cin >> t;
    while (t--)solve();
}