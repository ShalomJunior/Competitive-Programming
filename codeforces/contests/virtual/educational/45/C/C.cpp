#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<string> s(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int k = s[i].size();
        vector<int> pref(k);
        int mn = INF;
        for (int j = 0; j < k; j++) {
            pref[j] = (j ? pref[j - 1] : 0) + (s[i][j] == '(' ? 1 : -1);
            mn = min(mn, pref[j]);
        }
        a[i] = pref[k - 1];
        b[i] = mn;
        if (a[i] == 0 && b[i] == 0) tot++;
    }
    auto work = [&]() {
        map<int, int> h;
        for (int i = 0; i < n; i++) {
            if (a[i] <= 0 && a[i] == b[i]) {
                tot += h[-a[i]];
            }
            if (b[i] >= 0) h[a[i]]++;
        }
        };
    work();
    reverse(s.begin(), s.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    work();
    cout << tot << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
