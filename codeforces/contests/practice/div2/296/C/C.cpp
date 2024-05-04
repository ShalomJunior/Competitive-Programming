#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    set<int> x = { 0, w };
    multiset<int> dx = { w };
    set<int> y = { 0, h };
    multiset<int> dy = { h };
    for (int i = 0; i < n; i++) {
        char c;
        int p;
        cin >> c >> p;
        auto s = &x;
        auto ds = &dx;
        if (c == 'H') {
            s = &y;
            ds = &dy;
        }
        s->insert(p);
        int l = *(prev(s->lower_bound(p)));
        int r = *s->upper_bound(p);
        ds->erase(ds->find(r - l));
        ds->insert(p - l);
        ds->insert(r - p);
        int X = *prev(dx.end());
        int Y = *prev(dy.end());
        cout << 1LL * X * Y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
