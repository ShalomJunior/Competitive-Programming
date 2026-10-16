#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        mx = max(mx, ++mp[h]);
    }
    cout << n - mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}