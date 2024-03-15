#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first 
#define S second
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto& c : a) cin >> c;

    vector<int> b(n);
    set<Mine> s;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        b[i] = c;
        s.insert({ c, i });
    }

    vector<int> sup(n);

    sort(a.begin(), a.end());

    int ans = 1;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        int nb = a.end() - it;
        nb -= sup[i];
        nb = min(nb, n - i);
        cout << "->" << nb << endl;
        ans *= nb;
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}