#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 3e7;
void solve() {
    int p, n;
    cin >> p >> n;
    int cnt = 0;
    vector<bool> a(p);
    int x = 0;
    for (int i = 1; i <= min(n, INF); i++) {
        if (!a[x]) {
            a[x] = true;
            cnt++;
        }
        x += i;
        x %= p;
    }
    if (!a[x]) cnt++;
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}