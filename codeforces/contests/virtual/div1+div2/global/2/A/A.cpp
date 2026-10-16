#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> h;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        h[c].push_back(i);
    }
    int ans = 0;
    for (auto& [k, v] : h) {
        int m = v.size();
        for (int i = 0, j = 0; i < m; i++, j++) {
            if (v[i] != j) {
                ans = max(ans, v.back() - i);
                break;
            }
        }
        for (int i = m - 1, j = n - 1; i >= 0; i--, j--) {
            if (v[i] != j) {
                ans = max(ans, j - v[0]);
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}