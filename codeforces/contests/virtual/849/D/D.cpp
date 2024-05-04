#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    vector<int> pref(n), suff(n);
    set<char> let;
    for (int i = 0; i < n; i++) {
        let.insert(s[i]);
        pref[i] = let.size();
    }
    let.clear();
    for (int i = n - 1; i >= 0; i--) {
        let.insert(s[i]);
        suff[i] = let.size();
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int L = i ? pref[i - 1] : 0;
        int R = suff[i];
        ans = max(ans, L + R);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}