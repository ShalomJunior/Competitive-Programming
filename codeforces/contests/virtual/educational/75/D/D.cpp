#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> p(n);
    for (auto& [l, r] : p) cin >> l >> r;
    sort(p.begin(), p.end());
    auto check = [&](int mid) {
        int left = 0;
        int right = 0;
        int cost = 0;
        vector<int> save;
        for (auto& [l, r] : p) {
            if (l > mid) {
                right++;
                cost += l;
            }
            else if (r < mid) {
                left++;
                cost += l;
            }
            else {
                save.push_back(l);
            }
        }
        if (left > n / 2) return false;
        if (right > n / 2) return true;
        cost += accumulate(save.begin(), save.begin() + n / 2 - left, 0LL);
        left = n / 2;
        return cost + (n - left - right) * mid <= s;
        };
    int L = 0, R = INF;
    while (L + 1 < R) {
        int mid = (L + R) / 2;
        check(mid) ? L = mid : R = mid - 1;
    }
    cout << (check(R) ? R : L) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
