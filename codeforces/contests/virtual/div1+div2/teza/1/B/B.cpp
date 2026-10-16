#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int g = 0;
    for (int i = 0; i < n; i++) {
        if (g % a[i] == 0) {
            if (g == a[i]) {
                cout << "YES" << endl;
                return;
            }
            else {
                for (int j = i + 1; j < n; j++) {
                    int ng = __gcd(g, a[j]);
                    if (ng % a[i] == 0) g = ng;
                }
                if (g == a[i]) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        g = __gcd(g, a[i]);
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}