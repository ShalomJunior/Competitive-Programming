#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.insert(x);
    }
    int mn = *ms.begin();
    int mx = *prev(ms.end());
    int ans = INF;
    ms.erase(ms.begin());
    ans = min(ans, mx - *ms.begin());
    ms.insert(mn);
    ms.erase(prev(ms.end()));
    ans = min(ans, *prev(ms.end()) - mn);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}