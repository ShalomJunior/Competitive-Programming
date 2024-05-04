#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> id(N);
    for (int i = 0; i < n; i++) {
        id[s[i] - 'a'].push_back(i);
    }
    vector<int> p(m);
    for (auto& c : p) cin >> c;

    sort(p.begin(), p.end());
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(p.begin(), p.end(), i + 1);
        cnt[i] = p.end() - it;
    }
    for (int i = 0; i < N; i++) {
        long long ans = 0;
        for (auto& j : id[i]) ans += cnt[j];
        ans += count(s.begin(), s.end(), 'a' + i);
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}