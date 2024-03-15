#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int z = n + m - 1;
    vector<int> a(z);
    for (int i = 0; i < z; i++) {
        if (i <= m) a[i] = min(i + 1, n);
        else a[i] = n - (i - m);
    }
    int least = n / 2 + m / 2;
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << max(least, i) << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}