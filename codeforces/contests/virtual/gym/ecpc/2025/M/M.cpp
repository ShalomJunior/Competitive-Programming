#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> w(n);
    for (auto& c : h) cin >> c;
    for (auto& c : w) cin >> c;
    int L = 1, R = INF;
    auto go = [&](int mid) {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] >= mid) sum += w[i];
            else {
                ans = max(ans, sum);
                sum = 0;
            }
        }
        ans = max(ans, sum);
        return ans >= mid;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        if (go(mid)) {
            if (L == mid) go(R) ? L = R : R = L;
            else L = mid;
        }
        else {
            R = mid - 1;
        }
    }
    cout << L * L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
