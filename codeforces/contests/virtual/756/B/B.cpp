#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    if (a < b)swap(a, b);
    if (a == b) { cout << (a + b) / 4 << endl; return; }
    int ans = b / 2;
    a -= (b / 2) * 2;
    if (b % 2 != 0 && a > 2) {
        ans++; a -= 3;
    }
    ans += min(a / 4, b / 2);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}