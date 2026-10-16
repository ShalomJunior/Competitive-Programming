#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    auto check = [&](int mid) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min((mid - 1) / i, m);
        }
        return cnt < k;
        };
    int L = 1, R = n * m;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) {
                check(R) ? L = R : R = L;
            }
            else L = mid;
        }
        else {
            R = mid - 1;
        }
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
