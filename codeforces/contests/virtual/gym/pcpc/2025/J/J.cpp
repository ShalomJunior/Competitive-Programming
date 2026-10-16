#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9 + 5;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int L = 1, R = INF;
    auto go = [&](int mid) {
        vector<int> kill(n);
        for (int i = 0; i < n; i++) {
            int x = (a[i] + mid - 1) / mid;
            if (i + x - 1 < n)
                kill[i + x - 1]++;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt++;
            if (cnt >= k) return false;
            cnt -= kill[i];
        }
        return true;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? R = mid : L = mid + 1;
    }
    cout << R << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}