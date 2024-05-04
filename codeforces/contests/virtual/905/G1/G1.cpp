#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    deque<int> a(n), b(n);
    a[0] = m;
    for (int i = 1; i < n; i++) cin >> a[i];
    for (auto& c : b) cin >> c;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    while (!a.empty() && !b.empty()) {
        if (a.back() >= b.back()) {
            ans++;
            a.pop_back();
            b.pop_front();
        }
        else {
            a.pop_back();
            b.pop_back();
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}