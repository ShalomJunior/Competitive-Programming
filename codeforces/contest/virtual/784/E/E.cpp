#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 26;
void solve() {
    int n; cin >> n;
    vector<vector<string>> f(N), s(N);
    vector<unordered_map<string, int>> mf(N), ms(N);
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        f[str[0] - 'a'].push_back(str);
        mf[str[0] - 'a'][str]++;
        s[str[1] - 'a'].push_back(str);
        ms[str[1] - 'a'][str]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int z = f[i].size();
        for (int j = 0; j < z; j++) {
            string str = f[i][j];
            mf[i][str]--;
            ans += z - j - 1 - mf[i][str];
        }
        z = s[i].size();
        for (int j = 0; j < z; j++) {
            string str = s[i][j];
            ms[i][str]--;
            ans += z - j - 1 - ms[i][str];
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}