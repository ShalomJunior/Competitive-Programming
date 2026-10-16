#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int mx = 0;
    vector<int> cnt(N);
    for (auto& c : s) {
        mx = max(mx, ++cnt[c - 'a']);
    }
    int o = n - mx;
    cout << (mx > o + 1 ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}