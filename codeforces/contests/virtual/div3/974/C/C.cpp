#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e15;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mx = *max_element(a.begin(), a.end());
    int tot = accumulate(a.begin(), a.end(), 0LL);
    auto check = [&](int mid) {
        int cnt = 0;
        bool b = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx && b) {
                b = false;
                continue;
            }
            if (a[i] * n * 2 < tot + mid) cnt++;
        }
        return cnt >= (n + 2) / 2;
        };
    int L = 0, R = INF;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << (L == INF ? -1 : L) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}