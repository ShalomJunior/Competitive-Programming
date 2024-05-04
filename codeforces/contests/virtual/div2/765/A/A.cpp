#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int n, l; cin >> n >> l;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int j = N - 1; j >= 0; j--) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] & (1 << j)) cnt++;
        }
        if (2 * cnt > n) ans += 1 << j;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}