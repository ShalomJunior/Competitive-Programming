#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int curr = 0;
        for (auto& [k, v] : mp) {
            if (v >= i) curr += i;
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}