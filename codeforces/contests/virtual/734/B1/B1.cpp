#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    vector<int> a(26);
    for (auto& c : s) a[c - 'a']++;
    int ans = 0, ones = 0;
    for (auto& c : a) {
        if (c == 1) ones++;
        else ans += min(c / 2, 1);
    }
    cout << ans + ones / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}