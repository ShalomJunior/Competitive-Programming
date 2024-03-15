#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<Mine> seg;
    for (int i = 1, l = 0; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            seg.push_back({ l, i - 1 });
            l = i;
        }
        if (i == n - 1) seg.push_back({ l, n - 1 });
    }
    int ans = 0;
    map<int, int> l, r;
    for (auto& [x, y] : seg) {
        l[x] = r[y] = y - x + 1;
        ans = max(ans, l[x]);
    }
    int m = seg.size();
    for (int i = 1; i < m; i++) {
        int x1 = seg[i - 1].F, y1 = seg[i - 1].S;
        int x2 = seg[i].F, y2 = seg[i].S;
        int len = y1 - x1 + y2 - x2 + 2;
        if (x1 != y1 && a[y1 - 1] < a[x2]) ans = max(ans, len - 1);
        if (x2 != y2 && a[y1] < a[x2 + 1]) ans = max(ans, len - 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}