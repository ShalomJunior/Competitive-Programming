#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto get = [&](int pos) {
        vector<int> order;
        set<int> past;
        while (!past.count(pos)) {
            order.push_back(pos);
            past.insert(pos);
            pos = p[pos];
        }
        return order;
        };
    auto bodya = get(b);
    int zb = bodya.size();
    auto sasha = get(s);
    int zs = sasha.size();
    int x = 0, y = 0;
    for (int i = 0, pre = 0; i < min(k, zb); i++) {
        x = max(x, pre + (k - i) * a[bodya[i]]);
        pre += a[bodya[i]];
    }
    for (int i = 0, pre = 0; i < min(k, zs); i++) {
        y = max(y, pre + (k - i) * a[sasha[i]]);
        pre += a[sasha[i]];
    }
    if (x > y) cout << "Bodya";
    else if (x == y) cout << "Draw";
    else cout << "Sasha";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
