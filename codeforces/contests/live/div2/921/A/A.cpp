#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string pat;
    for (int i = 0; i < k; i++) pat += (char)'a' + i;
    string ans;
    for (int i = 0; i < n; i++) ans += pat;;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
