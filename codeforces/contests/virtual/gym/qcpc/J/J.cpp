#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (n > 3) {
        cout << -1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    do {
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = a[i];
            pref[i + 1] += pref[i];
        }
        bool f = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int d = pref[i] - pref[j];
                if (d != 2 && d != 3 && d != 5 && d != 7) {
                    f = false;
                }
            }
        }
        if (f) {
            for (auto& c : a) cout << c << " ";
            cout << endl;
            return;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}