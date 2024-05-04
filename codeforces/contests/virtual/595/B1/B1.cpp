#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c, --c;
    for (int i = 0; i < n; i++) {
        int j = i, cnt = 0;
        do {
            cnt++;
            j = a[j];
        } while (j != i);
        cout << cnt << " ";
    }
    cout << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}