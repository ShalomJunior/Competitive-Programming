#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 26;

void solve() {
    int k, n;
    cin >> k >> n;
    vector<string> w(k);
    for (auto& s : w) cin >> s;
    auto go = [&](string s, string t) {
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                pos.push_back(i);
            }
        }
        int m = pos.size();
        if (m == 0) return true;
        if (m > 2) return false;
        swap(t[pos[0]], t[pos[1]]);
        return s == t;
        };
    string s = w[0];
    vector<int> x, y;
    for (int j = 0; j < k; j++) {
        string t = w[j];
        int mis = 0;
        for (int i = 0; i < n; i++) mis += s[i] != t[i];
        if (mis % 2 || mis > 4) {
            cout << -1 << endl;
            return;
        }
        if (mis == 2) x.push_back(j);
        if (mis == 4) y.push_back(j);
    }
    if (!y.empty()) {

    }
    else if (!x.empty()) {

    }
    else {
        swap(s[0], s.back());
        cout << s << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
