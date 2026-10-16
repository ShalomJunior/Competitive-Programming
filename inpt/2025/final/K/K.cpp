#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    int ans = 0;
    while (ms.size() > 1) {
        int s = 0;
        s += *ms.begin();
        ms.erase(ms.begin());
        s += *ms.begin();
        ms.erase(ms.begin());
        ans += s;
        ms.insert(s);
    }
    if (ans < w) ans += w;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}