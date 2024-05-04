#include <bits/stdc++.h>

using namespace std;

void solve() {
    int mn = INT_MAX;

    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < n;i++) {
        int k; cin >> k;
        h[k]++;
        mn = min(mn, k);
    }

    int cnt = 0, ans = 0;
    while (cnt < n) {
        int curr = mn;
        while (h[curr] > 0) {
            h[curr]--;cnt++;
            if (h[curr] == 0) h.erase(curr);
            curr++;
        }
        //Important to erase this value created by the overflow of curr on line 22
        h.erase(curr);

        if (h[mn] == 0) {
            h.erase(mn);
            mn = h.begin()->first;
        }
        ans++;
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
