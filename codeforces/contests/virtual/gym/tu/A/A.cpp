#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int mx = (n + 1) / 2;
    set<pair<int, char>> s;
    s.insert({ a, 'R' });
    s.insert({ b, 'G' });
    s.insert({ c, 'B' });
    for (int i = n - (a + b + c); i > 0; i--) {
        auto f = *s.begin();
        s.erase(f);
        f.first++;
        s.insert(f);
    }
    if (max({ a, b, c }) <= mx) {
        while (s.size() > 1) {
            auto g = *prev(s.end());
            s.erase(g);
            auto f = *prev(s.end());
            s.erase(f);
            cout << g.second << f.second;
            if (--f.first) s.insert(f);
            if (--g.first) s.insert(g);
        }
        if (!s.empty()) {
            assert(s.begin()->first == 1);
            cout << s.begin()->second;
        }
    }
    else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
