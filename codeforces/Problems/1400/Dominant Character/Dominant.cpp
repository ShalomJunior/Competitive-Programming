#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        vector<int> cnt(3);
        for (int j = 0; j < 7 && i + j < n; j++) {
            cnt[s[i + j] - 'a']++;
            if (j && cnt[0] > max(cnt[1], cnt[2])) {
                ans = min(ans, j + 1);
            }
        }
    }
    cout << ((ans == INF) ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}