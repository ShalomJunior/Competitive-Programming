#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> id(N);
    for (int i = 0; i < n; i++) {
        id[s[i] - 'a'].push_back(i);
    }
    int ans = n;
    for (int i = 0; i < N; i++) {
        if (id[i].size() == 1) {
            ans = min(ans, id[i][0]);
        }
    }
    cout << (ans == n ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}