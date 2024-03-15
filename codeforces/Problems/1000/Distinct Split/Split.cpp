#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    unordered_map<char, int> l, r;
    for (auto& c : s)
        r[c]++;

    int mx = l.size() + r.size();

    for (auto& c : s) {
        l[c]++; r[c]--;
        if (r[c] == 0) r.erase(c);
        mx = max(mx, (int)(l.size() + r.size()));
    }

    cout << mx << endl;

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}