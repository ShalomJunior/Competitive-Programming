#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    set<int> s;
    for (int i = 0; i <= n; i++) s.insert(i);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.erase(a[i]);
    }
    a[n] = *s.begin();
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++) {
        ans[(i + k) % (n + 1)] = a[i];
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}