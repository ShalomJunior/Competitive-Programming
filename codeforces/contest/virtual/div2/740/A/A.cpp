#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0, add = 0;
    for (int k = 0; ; k++) {
        bool b = false;
        for (int i = (k & 1 ? 1 : 0); i < n - 1; i += 2) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                b = true;
            }
        }
        if (b) {
            ans++;
            ans += add;
            add = 0;
        }
        else {
            if (add == 1) break;
            add++;
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