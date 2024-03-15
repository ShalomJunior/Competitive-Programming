#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int m = 0, M = 1e9;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t, k;
        cin >> t >> k;
        if (t == 1) m = max(m, k);
        else if (t == 2) M = min(M, k);
        else a.push_back(k);
    }
    int ans = M - m + 1;
    for (auto& c : a) {
        if (m <= c && c <= M) ans--;
    }
    ans = max(ans, 0);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
