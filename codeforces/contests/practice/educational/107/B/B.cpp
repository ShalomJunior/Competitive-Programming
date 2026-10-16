#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> len;
    vector<pair<int, int>> p;
    int i = 0;
    while (i < n) {
        int j = 0;
        while (i + j < n && s[i + j] == s[i]) j++;
        if (s[i] == 'G') {
            len.push_back(j);
            p.push_back({ i, i + j - 1 });
        }
        i += j;
    }
    int m = p.size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, len[i] + (m > 1 ? 1 : 0));
        if (i > 0 && p[i - 1].second + 2 == p[i].first) {
            ans = max(ans, len[i - 1] + len[i] + (m > 2 ? 1 : 0));
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
