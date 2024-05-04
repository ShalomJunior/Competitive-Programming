#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;  cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int bad = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 - bad != a[i]) bad++;
    }
    cout << (bad / k + (bad % k ? 1 : 0)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}