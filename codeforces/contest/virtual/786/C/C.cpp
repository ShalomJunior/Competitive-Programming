#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    vector<int> cnt(26);
    for (auto& c : t) cnt[c - 'a']++;
    if (cnt[0]) {
        cout << ((cnt[0] == 1 && t.size() == 1) ? 1 : -1) << endl;
    }
    else cout << (1LL << (long long)(s.size())) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}