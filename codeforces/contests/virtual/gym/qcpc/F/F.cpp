#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n, m;
    cin >> n >> m;
    string x, y;
    cin >> x >> y;
    vector<int> Y(N);
    for (auto& c : y) Y[c - 'a']++;
    x = "#" + x;
    y = "#" + y;
    vector<vector<int>> cnt(n + 1, vector<int>(N));
    vector<vector<int>> h(N);
    for (int i = 1; i <= n; i++) {
        h[x[i] - 'a'].push_back(i);
        cnt[i] = cnt[i - 1];
        cnt[i][x[i] - 'a']++;
    }
    string ans;
    int pos = -1;
    for (int i = 0; i < m; i++) {
        for (int j = N - 1; j >= 0; j--) {
            char c = 'a' + j;
            if (!Y[j]) continue;
            auto it = upper_bound(h[j].begin(), h[j].end(), pos);
            if (it == h[j].end()) continue;
            int idx = *it;
            bool f = true;
            for (int k = 0; k < N; k++) {
                if (cnt[n][k] - cnt[idx][k] < Y[k] - (k == j)) f = false;
            }
            if (f) {
                Y[j]--;
                ans += c;
                pos = idx;
                break;
            }
        }
    }
    cout << (ans.empty() ? "-1" : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}