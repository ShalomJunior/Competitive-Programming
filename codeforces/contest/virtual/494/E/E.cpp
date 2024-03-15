#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d, k; cin >> n >> d >> k;
    if (n < d + 1 || (k == 1 && d >= 2)) {
        cout << "NO" << endl;
        return;
    }
    vector<pair<int, int>> ans;
    int cnt = 0;
    for (int i = 1; i <= d; i++) {
        ans.push_back({ i, i + 1 });
        cnt++;
    }
    int node = d + 1;
    for (int i = 2; node < n && i <= d; i++) {
        if (k < 3) continue;
        queue<int> q; q.push(i);
        for (int j = 0; j < min(i - 1, d + 1 - i); j++) {
            queue<int> t;
            while (!q.empty()) {
                int r = q.front(); q.pop();
                for (int c = 0; node < n && c < (r == i ? k - 2 : k - 1); c++) {
                    ans.push_back({ r, ++node });
                    t.push(node);
                }
            }
            q = t;
        }
    }
    if (node < n) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (auto& [l, r] : ans) {
        cout << l << " " << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}