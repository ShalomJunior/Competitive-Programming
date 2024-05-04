#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    map<pair<int, int>, int> h;
    int ans = 0, any = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            int g = gcd(a[i], b[i]);
            a[i] /= g; b[i] /= g;
            if (h.count({ a[i], b[i] })) {
                ans = max(ans, ++h[{a[i], b[i]}]);
            }
            else {
                ans = max(ans, ++h[{-a[i], -b[i]}]);
            }

        }
        else if (!b[i]) any++;
    }
    cout << ans + any << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}