#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x % k]++;
    }
    int ans = a[0] / 2;
    for (int i = 1; i < k / 2; i++) {
        ans += min(a[i], a[k - i]);
    }
    if (k & 1) ans += min(a[k / 2], a[k / 2 + 1]);
    else ans += a[k / 2] / 2;
    cout << 2 * ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}