#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    long long  ans = 0;
    long long ma = *min_element(a.begin(), a.end());
    long long mb = *min_element(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        if (a[i] > ma || b[i] > mb)
            ans += max(a[i] - ma, b[i] - mb);
    }

    cout << ans << endl;

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}