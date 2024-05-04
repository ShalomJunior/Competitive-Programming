#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n), b(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            d[j] += min(a[j - i], b[j]);
            a[j - i] -= min(a[j - i], b[j]);
        }
    }

    for (auto& v : d)
        cout << v << " ";
    cout << endl;

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}