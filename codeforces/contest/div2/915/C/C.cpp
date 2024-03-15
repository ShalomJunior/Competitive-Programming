#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n; string s;
    cin >> n >> s;
    vector<vector<int>> p(N);
    for (int i = 0; i < n; ++i) {
        p[s[i] - 'a'].push_back(i);
    }
    int start = 0;
    vector<int> idx;
    while (start < n) {
        for (int i = N - 1; i >= 0; --i) {
            auto it = lower_bound(p[i].begin(), p[i].end(), start);
            if (it == p[i].end()) continue;
            idx.push_back(*it);
            start = *it + 1;
            break;
        }
    }
    int m = idx.size();
    int move = 0;
    for (int j = m - 1; j >= 0; --j) {
        if (s[idx[j]] == s[idx[0]]) {
            move = m - 1 - j;
            break;
        }
    }
    string ans = s;
    for (int i = m - 1, j = 0; i >= 0; i--, j++) {
        ans[idx[j]] = s[idx[i]];
    }
    cout << (is_sorted(ans.begin(), ans.end()) ? move : -1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
