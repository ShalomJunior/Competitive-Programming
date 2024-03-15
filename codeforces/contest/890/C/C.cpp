#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto go = [&](int i, int mid) {
        int j;
        bool b = false;
        for (j = i + 1; j < n; j++) {
            if (a[j] >= mid - (j - i)) {
                b = true;
                break;
            }
        }
        if (!b) return false;
        int cnt = 0;
        while (j >= i) {
            cnt += max(mid - (j - i) - a[j], 0LL);
            j--;
        }
        return cnt <= k;
        };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int L = a[i], R = INF;
        while (L < R) {
            int mid = (L + R) / 2;
            bool b = go(i, mid);
            if (b) {
                if (L == mid) go(i, R) ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        ans = max(ans, L);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}