#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    set<int> s(a.begin(), a.end());
    int ans = 0;
    while (!s.empty()) {
        ans++;
        s.erase(*prev(s.end()));
        if (!s.empty()) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
