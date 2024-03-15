#include <bits/stdc++.h>
using namespace std;

void solve(int i) {
    cout << "Case #" << i << ": ";
    int s, d, k; cin >> s >> d >> k;
    string ans = (2 * (s + d) >= k + 1 && s + 2 * d >= k ? "YES" : "NO");
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}