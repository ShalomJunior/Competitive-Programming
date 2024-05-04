#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int INF = 1e9;
vector<int> get(string s, string p, bool flag) {
    if (flag) {
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
    }
    int n = s.length();
    int m = p.length();
    vector<vector<int>> idx(N);
    for (int i = 0; i < n; i++) {
        idx[s[i] - 'a'].push_back(i);
    }
    vector<int> ans(m + 1, n);
    ans[0] = -1;
    int start = 0;
    for (int i = 0; i < m; i++) {
        int j = p[i] - 'a';
        auto it = lower_bound(idx[j].begin(), idx[j].end(), start);
        if (it == idx[j].end()) break;
        ans[i + 1] = *it;
        start = ans[i + 1] + 1;
    }
    if (flag) {
        vector<int> temp(m + 1);
        for (int i = 0; i <= m; i++) {
            if (ans[i] == -1)
                temp[i] = n;
            else if (ans[i] == INF)
                temp[i] = -1;
            else
                temp[i] = n - 1 - ans[i];
        }
        ans = temp;
    }
    return ans;
}

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    auto f = get(a, b, false);
    auto g = get(a, b, true);
    auto check = [&](int len, string& str) {
        for (int i = 0; i + len - 1 < m; i++) {
            int x = f[i];
            int y = g[m - (i + len)];
            if (x < y) {
                str = (i ? b.substr(0, i) : "") + (i + len == m ? "" : b.substr(i + len, m - (i + len)));
                return true;
            }
        }
        return false;
        };
    int L = 0, R = m;
    string ans;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid, ans) ? R = mid : L = mid + 1;
    }
    cout << (R == m ? "-" : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
