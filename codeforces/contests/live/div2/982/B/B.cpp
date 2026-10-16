#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto check = [&](int c) {
        int j = 0;
        while (a[j] != c) j++;
        int ans = j;
        for (int k = j + 1; k < n; k++) {
            if (a[k] > c) ans++;
        }
        return ans;
        };
    int ans = INF;
    for (auto& c : a) {
        ans = min(ans, check(c));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}