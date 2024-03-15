#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int m = 0, M = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            if (a[i] < a[m]) m = i;
            if (a[i] > a[M]) M = i;
        }
    }
    int L = min(m, M), R = max(m, M);
    cout << min({ R + 1, n - L, L + 1 + n - R }) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}