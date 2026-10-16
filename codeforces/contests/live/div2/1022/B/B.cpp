#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
void solve() {
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << (x ? x : -1) << endl;
        return;
    }
    vector<int> a;
    for (int j = 0; j < N; j++) {
        if (x & (1 << j)) {
            a.push_back(1 << j);
        }
    }
    while (a.size() > n) {
        a[0] |= a.back();
        a.pop_back();
    }
    int u = x;
    int ans = x;
    if (a.size() < n) {
        int r = n - a.size();
        ans += r;
        if (r & 1) {
            u = u ^ 1;
            a.push_back(1);
        }
    }
    int z = a.size();
    auto fx = [&](int mask) {
        for (int i = 0; i < z; i++) {
            int b = a[i] & mask;
            if (b && a[i] != mask) return i;
        }
        return z;
        };
    auto gx = [&](int mask) {
        for (int i = 0; i < z; i++) {
            int b = a[i] & mask;
            if (!b) return i;
        }
        return z;
        };
    if (u != x) {
        if (fx(1) < z) {
            ans--;
        }
        else {
            if (gx(1) < z) {
                ans++;
            }
            else {
                ans++;
                if (fx(2) < z) {
                    ans -= 2;
                }
                else {
                    ans += 2;
                }
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
