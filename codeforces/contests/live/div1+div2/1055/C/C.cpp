#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        cnt[i] = cnt[i - 1] + (a[i - 1] == a[i]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int m = r - l + 1;
        int s = pref[r] - pref[l - 1];
        if (s % 3 || m % 3) {
            cout << -1 << endl;
            continue;
        }
        if (cnt[r] - cnt[l + 1] > 0) {
            cout << m / 3;
        }
        else {
            cout << m / 3 + 1;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
