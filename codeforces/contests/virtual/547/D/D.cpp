#include <bits/stdc++.h>
using namespace std;

const int L = 26;
void solve() {
    int n; cin >> n;
    string l, r; cin >> l >> r;
    vector<vector<int>> s(L + 1);
    for (int i = 0; i < n; i++) {
        if (r[i] == '?') s[L].push_back(i);
        else s[r[i] - 'a'].push_back(i);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (l[i] == '?')continue;
        int d = l[i] - 'a';
        if (s[d].size()) {
            ans.push_back({ i + 1, s[d].back() + 1 });
            s[d].pop_back();
        }
        else if (s[L].size()) {
            ans.push_back({ i + 1, s[L].back() + 1 });
            s[L].pop_back();
        }
    }
    for (int i = 0; i < n; i++) {
        if (l[i] == '?') {
            for (int j = 0; j <= L; j++) {
                if (s[j].size()) {
                    ans.push_back({ i + 1, s[j].back() + 1 });
                    s[j].pop_back();
                    break;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto& [i, j] : ans) {
        cout << i << " " << j << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}