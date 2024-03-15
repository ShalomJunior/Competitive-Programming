#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n), cum(n);
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i) { cum[i] = v[i] + cum[i - 1]; }
        else { cum[i] = v[i]; }
        um[cum[i]] = i + 1;
    }

    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (cum[n - 1] % i != 0)continue;
        int need = cum[n - 1] / i;
        int ths = 0;
        int last = 0;
        int curr = need;
        while (um.find(curr) != um.end()) {
            ths = max(ths, um[curr] - last);
            last = um[curr];
            if (curr == cum[n - 1]) {
                ans = min(ans, ths);
            }
            curr += need;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}