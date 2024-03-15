#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].resize(k + 1);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            a[i][k] = max(a[i][k], a[i][j] - j + 1);
        }
    }
    sort(a.begin(), a.end(), [&](const vector<int>& x, const vector<int>& y) {
        return x.back() < y.back();
        });
    auto go = [&](int mid) {
        int power = mid;
        for (int i = 0; i < n; i++) {
            int k = a[i].size() - 1;
            if (power < a[i][k]) return false;
            power += k;
        }
        return true;
        };
    int L = 1, R = 1e12;
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}