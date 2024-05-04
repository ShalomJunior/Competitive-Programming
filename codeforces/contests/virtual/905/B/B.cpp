#include <bits/stdc++.h>
using namespace std;

const int L = 26;
void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> cnt(L);
    for (auto& c : s) cnt[c - 'a']++;
    int odd = 0;
    for (auto& c : cnt) {
        if (c & 1) odd++;
    }
    odd -= k;
    if (odd < 0) odd = 0;
    cout << (odd > 1 ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}