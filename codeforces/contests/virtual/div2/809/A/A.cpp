#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    string ans(m, 'B');
    for (int i = 0; i < n; i++) {
        int x = a[i] - 1;
        int y = m - 1 - x;
        if (x > y)swap(x, y);
        if (ans[x] != 'A') ans[x] = 'A';
        else if (ans[y] != 'A') ans[y] = 'A';
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}