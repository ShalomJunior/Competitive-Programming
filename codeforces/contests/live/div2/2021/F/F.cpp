#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 365;
const int M = 20;
void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (auto& c : d) cin >> c;
    int j = 0;
    int cnt = 0;
    int bad = 0;
    int ans = 0;
    bool reset = true;
    for (int i = 1; i <= N; i++) {
        if (!reset) {
            if (bad + cnt < M) {
                bad += cnt;
            }
            else {
                ans++;
                bad = 0;
                cnt = 0;
                reset = true;
            }
        }
        if (j < n && d[j] == i) {
            reset = false;
            cnt++;
            j++;
        }
    }
    if (cnt) ans++;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
