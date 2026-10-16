#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int s = accumulate(a.begin(), a.end(), 0LL);
    if (max(a[n - 1] - 1, a[n - 2]) - a[0] > k) {
        cout << "Jerry";
    }
    else {
        cout << (s & 1 ? "Tom" : "Jerry");
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
