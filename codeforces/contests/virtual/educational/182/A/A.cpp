#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int l = 1; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int x = pref[l];
            int y = pref[r] - pref[l];
            int z = pref[n] - pref[r];
            set<int> s = { x % 3, y % 3, z % 3 };
            int m = s.size();
            if (m == 1 || m == 3) {
                cout << l << " " << r << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
