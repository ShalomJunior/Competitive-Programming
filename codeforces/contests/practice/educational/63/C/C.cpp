#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int INF = 1e9;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> pos(N);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    auto go = [&](int i) {
        if (pos[i].empty()) return INF;
        int ans = max(pos[i][0] + 1, n - pos[i].back());
        for (int j = 1; j < pos[i].size(); j++) {
            ans = max(ans, pos[i][j] - pos[i][j - 1]);
        }
        return ans;
        };
    vector<int> ans;
    for (int i = 0; i < N; i++) ans.push_back(go(i));
    cout << *min_element(ans.begin(), ans.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}