#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, vector<string>> h;
    for (int i = 0;i < n; i++) {
        string s; cin >> s;
        h[s.length()].push_back(s);
    }
    vector<string> ans;
    for (auto& [len, vec] : h) {
        sort(vec.begin(), vec.end());
        if (vec[0] != vec.back()) {
            cout << "NO" << endl;
            return;
        }
        if (ans.empty()) for (auto& s : vec) ans.push_back(s);
        else {
            for (int i = ans.size() - 1; i >= 0; i--) {
                if (vec[0].find(ans[i]) == -1) {
                    cout << "NO" << endl;
                    return;
                }
            }
            for (auto& s : vec)ans.push_back(s);
        }
    }
    cout << "YES" << endl;
    for (auto& s : ans)cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}