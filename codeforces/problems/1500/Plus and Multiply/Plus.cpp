#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b, n;
bool go(int curr) {
    cout << "curr = " << curr << "n = " << n << endl;
    if (curr == n || b == 1 || (n - curr) % b == 0)
        return true;
    if (curr > n) return false;

    bool ans = go(curr + b);
    if (a != 1)ans |= go(curr * a);
    return ans;
}

void solve() {
    cin >> n >> a >> b;
    cout << ((go(1) ? "YES" : "NO")) << endl;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}