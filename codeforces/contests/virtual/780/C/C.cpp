#include <bits/stdc++.h>
using namespace std;

const int L = 26;
void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> id(L);
    for (int i = 0; i < n; i++) {
        id[s[i] - 'a'].push_back(i);
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int j = s[i] - 'a';
        auto it = lower_bound(id[j].begin(), id[j].end(), i);
        if (it == id[j].begin()) {
            dp[i] = 1 + (i ? dp[i - 1] : 0);
            continue;
        }
        --it;
        dp[i] = min(dp[i - 1] + 1, i - *it - 1 + (*it ? dp[*it - 1] : 0));
    }
    cout << dp[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}