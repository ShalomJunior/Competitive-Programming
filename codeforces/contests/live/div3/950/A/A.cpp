#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<char, int> h;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        h[c]++;
    }
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        if (h['A' + i] < m) ans += m - h['A' + i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
