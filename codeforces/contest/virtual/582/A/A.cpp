#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x & 1 ? odd++ : even++;
    }
    cout << min(even, odd) << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}