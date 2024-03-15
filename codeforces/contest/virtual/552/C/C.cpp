#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> food = { 1, 2, 3, 1, 3, 2, 1 };
    auto go = [&](int mid, int start) {
        int weeks = mid / 7;
        int ax = weeks * 3, bx = weeks * 2, cx = weeks * 2;
        for (int i = 0; i < mid % 7; i++) {
            int j = (start + i) % 7;
            if (food[j] == 1) ax++;
            else if (food[j] == 2) bx++;
            else  cx++;
        }
        return (ax <= a && bx <= b && cx <= c);
        };
    int ans = 0;
    for (int i = 0; i < food.size(); i++) {
        int L = 0, R = 1e12;
        while (L < R) {
            int mid = (L + R) / 2;
            bool b = go(mid, i);
            if (b) {
                if (L == mid) {
                    go(R, i) ? L = R : R = L;
                }
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
    solve();
}