#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, string> mp;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string id, name;
        cin >> id >> name;
        mp[id] = name;
    }
    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            cnt[s]++;
        }
    }
    int mx = 0;
    vector<string> ans;
    for (auto it = cnt.begin(); it != cnt.end(); it++) mx = max(mx, it->second);
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second == mx)ans.push_back(mp[it->first]);

    }

    sort(ans.begin(), ans.end());
    if (ans.size() != 0)for (auto a : ans) cout << a << endl;
    else cout << "Something is very wrong" << endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)solve();
}