#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int l = 0;
    while (l < n && a[l] == a[0])l++;
    int r = n - 1;
    while (r >= 0 && a[r] == a[n - 1])r--;
    if (a[0] == a[n - 1]) {
        cout << max(r - l + 1, 0) << endl;
    }
    else {
        cout << min(n - l, r + 1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
