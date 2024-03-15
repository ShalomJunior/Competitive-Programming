#include <bits/stdc++.h>

using namespace std;
void solve() {
    string s; cin >> s;
    unordered_map<char, int> mp;
    int mx = 0;
    for (auto& c : s) {
        mp[c]++;
        mx = max(mx, mp[c]);
    }

    if (mx == 4) cout << -1 << endl;
    else if (mx == 3) cout << 6 << endl;
    else cout << 4 << endl;
}

using namespace std;

int main() {
    int t; cin >> t;
    while (t--)solve();
}