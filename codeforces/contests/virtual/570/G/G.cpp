#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x, f; cin >> x >> f;
        --x;
        if (f) a[x]++;
    }
    sort(a.rbegin(), a.rend());
    long long ans = a[0];
    set<int> s; s.insert(a[0]);
    for (int i = 1; i < n; i++) {
        if (!a[i]) break;
        if (*s.begin() > a[i]) {
            ans += a[i];
            s.insert(a[i]);
        }
        else {
            if (*s.begin() == 1) break;
            s.insert(min(a[i], *s.begin() - 1));
            ans += *s.begin();
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}