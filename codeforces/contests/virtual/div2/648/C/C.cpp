#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x - 1] = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x - 1] = i;
    }
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        h[(a[i] + n - b[i]) % n]++;
    }
    int ans = 0;
    for (auto& [k, v] : h)ans = max(ans, v);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}