#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) & 1) {
        cout << -1 << endl;
        return;
    }
    multiset<int> ms;
    for (auto& v : { a, b, c }) {
        if (v) ms.insert(v);
    }
    int ans = 0;
    while (ms.size() >= 2) {
        int x = *prev(ms.end());
        ms.erase(prev(ms.end()));
        int y = *prev(ms.end());
        ms.erase(prev(ms.end()));
        x--, y--;
        ans++;
        if (x) ms.insert(x);
        if (y) ms.insert(y);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
