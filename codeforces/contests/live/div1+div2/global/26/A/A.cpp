#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (a[0] == a[n - 1]) {
        cout << "NO" << endl;
        return;
    }
    string ans(n, 'R');
    ans[n - 2] = 'B';
    cout << "YES" << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}