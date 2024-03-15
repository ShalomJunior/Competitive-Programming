#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, w; cin >> n >> w;
    vector<int> a(n);
    for (int i = 0, sum = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
        a[i] = sum;
    }
    int less = *min_element(a.begin(), a.end());
    int great = *max_element(a.begin(), a.end());
    int L = (less < 0 ? -less : 0);
    int R = w - (great > 0 ? great : 0);
    if (less < -w || great > w || L > R) { cout << 0 << endl;  return; }
    cout << R - L + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}