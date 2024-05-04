#include <bits/stdc++.h>
using namespace std;

const int N = 5;
void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for (auto& s : a) cin >> s;
    vector<vector<int>> cnt(n, vector<int>(N));
    for (int i = 0; i < n; i++) {
        for (auto& c : a[i]) {
            cnt[i][c - 'a']++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<int> h;
        for (int j = 0; j < n; j++) {
            h.push_back(2 * cnt[j][i] - a[j].size());
        }
        sort(h.rbegin(), h.rend());
        if (h[0] <= 0) continue;
        vector<int> pre(n);
        int sum = 0;
        bool b = false;
        for (int j = 0; j < n; j++) {
            sum += h[j];
            if (sum <= 0) {
                ans = max(ans, j);
                b = true;
                break;
            }
        }
        if (!b) ans = n;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}