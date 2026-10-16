#include <bits/stdc++.h>
using namespace std;

const int K = 1e7 + 5;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> pref(n + 2);
    vector<int> suff(n + 2);
    for (int i = 1; i <= n; i++) pref[i] = __gcd(pref[i - 1], a[i]);
    for (int i = n; i >= 1; i--) suff[i] = __gcd(suff[i + 1], a[i]);
    vector<bool> in(K);
    for (int i = 1; i <= n; i++) {
        int g = __gcd(pref[i - 1], suff[i + 1]);
        in[g] = true;
    }
    vector<bool> ans(K);
    for (int i = 2; i < K; i++) {
        for (int j = i; j < K; j += i) {
            if (in[j])
                ans[i] = true;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        if (n == 1) {
            cout << "Yes\n";
            continue;
        }
        if (k > K) {
            cout << "NO\n";
            continue;
        }
        cout << (k == 1 || ans[k] ? "YES" : "NO") << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}