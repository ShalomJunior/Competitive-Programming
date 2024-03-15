#include <bits/stdc++.h>

using namespace std;


void solve() {

    int n; cin >> n;
    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) cin >> b[i];

    multiset<long long> s;
    long long delta = 0;
    for (int i = 0; i < n; i++) {
        s.insert(a[i] - delta);

        long long ans = 0;

        while (!s.empty() && *s.begin() + delta < b[i]) {
            ans += *s.begin() + delta;
            s.erase(s.begin());
        }

        ans += (long long)s.size() * b[i];
        delta -= b[i];

        cout << ans << " ";
    }
    cout << endl;

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}