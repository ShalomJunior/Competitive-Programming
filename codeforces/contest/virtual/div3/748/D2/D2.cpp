#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0; i <= n / 2 + 1; i++) {
        if (i > 0 && a[i - 1] == a[i]) continue;
        set<int> div;
        map<int, int> cnt;
        for (int j = i; j < n; j++) {
            int delta = a[j] - a[i];
            if (delta == 0) {
                cnt[delta]++;
            }
            else {
                for (int k = 1; k * k <= delta; k++) {
                    if (delta % k == 0) {
                        int x = k, y = delta / k;
                        div.insert(x);
                        cnt[x]++;
                        if (x != y) {
                            div.insert(y);
                            cnt[y]++;
                        }
                    }
                }
            }
        }
        if (cnt[0] >= n / 2) {
            cout << -1 << endl;
            return;
        }
        vector<int> g;
        for (auto it = div.begin(); it != div.end(); it++) {
            if (cnt[0] + cnt[*it] >= n / 2) {
                g.push_back(*it);
            }
        }
        if (!g.empty()) ans = max(ans, g.back());
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}