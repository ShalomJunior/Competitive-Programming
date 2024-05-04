#include <bits/stdc++.h>

using namespace std;

int sm(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    if (sm(n % 1000) == sm(n / 1000)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}