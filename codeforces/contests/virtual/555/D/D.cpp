#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 2e9;
void solve() {
    int n, k; cin >> n >> k;
    if ((k * (k + 1)) / 2 > n) {
        cout << "NO" << endl;
        return;
    }
    int L = 1, R = INF;
    auto go = [&](int mid) {
        int cnt = k * (mid + (mid + k - 1)) / 2;
        return cnt <= n;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        bool b = go(mid);
        if (b) {
            if (L == mid) {
                go(R) ? L = R : R = L;
            }
            else L = mid;
        }
        else R = mid - 1;
    }
    vector<int> ans(k);
    iota(ans.begin(), ans.end(), L);
    int r = n;
    for (auto& c : ans) r -= c;
    for (int i = k - 1; i > 1 && r; i--, r--) {
        ans[i]++;
    }
    if (r) {
        if (ans[0] != 1) ans[1]++;
        else if (k <= 3) {
            cout << "NO" << endl;
            return;
        }
        else ans.back()++;
    }
    cout << "YES" << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}