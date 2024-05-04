#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
        return;
    }
    for (int i = N; i >= 0; i--) {
        int mn = 0;
        for (int j = 0; j < i; j++) mn += 1 << j;
        if (mn > k) continue;
        cout << mn << " " << k - mn << " ";
        for (int j = 2; j < n; j++) cout << 0 << " ";
        cout << endl;
        return;
    }
    assert(false);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
