#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 26;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    vector<int> pref(N);
    vector<vector<int>>cnt(N, vector<int>(N));
    for (int k = 0; k < n; k++) {
        int j = s[k] - 'a';
        for (int i = 0; i < N; i++) {
            cnt[i][j] += pref[i];
            ans = max(ans, cnt[i][j]);
        }
        pref[j]++;
        ans = max(ans, pref[j]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}