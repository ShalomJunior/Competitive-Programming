#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int max = 0;
    for (auto& c : a) {
        cin >> c;
        max += abs(c);
    }
    int seg = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) cnt++;
        if (i == n - 1 || a[i] > 0) {
            if (cnt)seg++;
            cnt = 0;
        }
    }
    cout << max << " " << seg << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}