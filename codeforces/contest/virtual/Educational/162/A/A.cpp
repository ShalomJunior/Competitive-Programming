#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (auto& c : a) {
        cin >> c;
        cnt += c;
    }
    int l = 0;
    while (l < n && a[l] == 0) l++;
    int r = n - 1;
    while (r >= 0 && a[r] == 0) r--;
    cout << (l > r ? 0 : r - l + 1 - cnt) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
