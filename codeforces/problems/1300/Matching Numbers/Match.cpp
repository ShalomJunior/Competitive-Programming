#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    if (n % 2 == 0) { cout << "NO" << endl; return; }

    cout << "YES" << endl;
    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i].F = i + 1;
        int add = 2 * (n - i);
        ans[i].S = (add > n) ? add : n + add;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i].F << " " << ans[i].S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}