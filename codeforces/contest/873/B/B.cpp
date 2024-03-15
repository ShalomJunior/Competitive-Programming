#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ans = gcd(ans, abs(a - i));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}