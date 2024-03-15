#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa >= xb) {
        cout << "Draw" << endl;
        return;
    }
    auto normalize = [&](pair<int, int>& p) {
        p.second = min(p.second, w);
        p.first = max(p.first, 1);
        p.second = max(p.second, 1);
        };
    int delta = xb - xa;
    if (delta & 1) {
        pair<int, int> a, b;
        a = { ya - (delta + 1) / 2 , ya + (delta + 1) / 2 };
        b = { yb - delta / 2, yb + delta / 2 };
        normalize(a);
        normalize(b);
        cout << (b.first < a.first || a.second < b.second ? "Draw" : "Alice") << endl;
    }
    else {
        pair<int, int> a, b;
        a = { ya - delta / 2 , ya + delta / 2 };
        b = { yb - delta / 2, yb + delta / 2 };
        normalize(a);
        normalize(b);
        cout << (a.first < b.first || b.second < a.second ? "Draw" : "Bob") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
