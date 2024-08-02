#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, vector<int>> p;
    for (auto& c : a) {
        cin >> c;
        p[c % k].push_back(c);
    }
    int odds = 0;
    for (auto& [_, v] : p) {
        int m = v.size();
        if (m & 1) odds++;
    }
    if (odds > 1 || (n % 2 == 0 && odds > 0)) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for (auto& [_, v] : p) {
        int m = v.size();
        sort(v.begin(), v.end());
        if (m & 1) {
            if (m == 1) continue;
            vector<int> pref = { 0 };
            int last = 0;
            for (int i = 0; i + 1 < m; i += 2) {
                pref.push_back(last += (v[i + 1] - v[i]) / k);
                last = pref.back();
            }
            vector<int> suff = { 0 };
            last = 0;
            for (int i = m - 2; i >= 0; i -= 2) {
                suff.push_back(last + (v[i + 1] - v[i]) / k);
                last = suff.back();
            }

            int add = INF;
            int l = 0;
            int r = suff.size() - 1;
            for (int i = 0; i < m; i += 2) {
                add = min(add, pref[l] + suff[r]);
                l++, r--;
            }
            ans += add;
        }
        else {
            for (int i = 0; i + 1 < m; i += 2) {
                ans += (v[i + 1] - v[i]) / k;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
