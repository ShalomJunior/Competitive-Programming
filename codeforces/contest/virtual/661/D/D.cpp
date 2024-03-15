#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    set<int> o, z;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') z.insert(i);
        else o.insert(i);
    }
    vector<int> ans(n);
    int p = 0;
    while (!o.empty() || !z.empty()) {
        p++;
        if (z.empty()) {
            ans[*o.begin()] = p;
            o.erase(o.begin());
        }
        else if (o.empty()) {
            ans[*z.begin()] = p;
            z.erase(z.begin());
        }
        else {
            auto& f = o;
            auto& g = z;
            bool flip = false;
            if (*g.begin() < *f.begin()) {
                swap(f, g);
                flip = true;
            }
            int last = *f.begin();
            for (int i = 0; ; i++) {
                if (i & 1) {
                    auto it = g.lower_bound(last);
                    if (it == g.end()) break;
                    ans[*it] = p;
                    last = *it;
                    g.erase(it);
                }
                else {
                    auto it = f.lower_bound(last);
                    if (it == f.end()) break;
                    ans[*it] = p;
                    last = *it;
                    f.erase(it);
                }
            }
            if (flip) swap(f, g);
        }
    }
    cout << p << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}