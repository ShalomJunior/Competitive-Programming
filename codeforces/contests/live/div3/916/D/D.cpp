#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    set<Mine> sa, sb, sc;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa.insert({ a[i], i });
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sb.insert({ b[i], i });
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sc.insert({ c[i], i });
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sb.erase({ b[i], i });
        sc.erase({ c[i], i });
        auto pb = *prev(sb.end());
        auto pc = *prev(sc.end());
        if (pb.F > pc.F) {
            sc.erase({ c[pb.S], pb.S });
            ans = max(ans, a[i] + pb.F + prev(sc.end())->F);
            sc.insert({ c[pb.S], pb.S });
            if (sb.size() > 1) ans = max(ans, a[i] + pc.F + prev(prev(sb.end()))->F);
        }
        else {
            sb.erase({ b[pc.S], pc.S });
            ans = max(ans, a[i] + pc.F + prev(sb.end())->F);
            sb.insert({ b[pc.S], pc.S });
            if (sc.size() > 1) ans = max(ans, a[i] + pb.F + prev(prev(sc.end()))->F);
        }
        sb.insert({ b[i], i });
        sc.insert({ c[i], i });
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
