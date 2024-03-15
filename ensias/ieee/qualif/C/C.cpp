#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> wd(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        wd[i] = s; mp[s]++;
    }

    int ans = 0;
    for (auto& [k, v] : mp)
        if (v > 1) ans += v - 1;

    for (int i = 0; i < n; i++) {
        if (mp[wd[i]] == 1)continue;
        for (int j = 0; j < 4; j++) {
            bool done = false;
            for (char c = '0'; c <= '9'; c++) {
                string pr = wd[i]; pr[j] = c;
                if (mp.find(pr) == mp.end()) {
                    mp[wd[i]]--; mp[pr]++;
                    wd[i] = pr;
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << wd[i] << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}