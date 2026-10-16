#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x;
    cin >> x;
    int j = 2;
    int ans = 1;
    int id = 2;
    while (id < x) {
        id += j;
        j++;
        ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
