#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x] = i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (h[i] > h[i + 1]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}