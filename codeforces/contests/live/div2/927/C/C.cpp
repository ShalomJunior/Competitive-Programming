#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> state;
    int rem = 0;
    auto check = [&](int mid) {
        state = a;
        int have = k;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) {
                int d = mid - a[i];
                if (have < d) return false;
                state[i] += d;
                have -= d;
            }
        }
        rem = have;
        return true;
        };
    int L = 0, R = 1e15;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    check(L);
    int sup = 0;
    for (int i = 0; i < n; i++) {
        if (rem && state[i] == L) {
            state[i]++;
            rem--;
        }
        if (state[i] > L) sup++;
    }
    int ans = L * n - (n - 1) + sup;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
