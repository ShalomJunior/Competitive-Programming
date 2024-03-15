#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << endl;
        return;
    }
    int l = 0;
    while (a[l] == l + 1)l++;
    int r = n - 1;
    while (a[r] == r + 1)r--;
    bool flag = false;
    for (int i = l; i <= r; i++) {
        flag |= a[i] == i + 1;
    }
    cout << (flag ? 2 : 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}