#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 1; ; i++) {
        int  m = pow(x, i);
        for (int j = 0; j < n; j++) {
            if (a[j] % m == 0) continue;
            long long tot = accumulate(a.begin(), a.end(), 0LL);
            long long sup = accumulate(a.begin(), a.begin() + j, 0LL);
            long long ans = tot * i + sup;
            cout << ans << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}