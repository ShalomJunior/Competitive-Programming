#include <bits/stdc++.h>
using namespace std;

void solve(int i) {
    cout << "Case #" << i << ": ";
    int r, c, a, b; cin >> r >> c >> a >> b;
    string ans = (r > c ? "YES" : "NO");
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}