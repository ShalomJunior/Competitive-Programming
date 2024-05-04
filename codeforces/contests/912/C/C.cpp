#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    long long ans = 0, sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if (i == 0 || sum > 0) ans += sum;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
