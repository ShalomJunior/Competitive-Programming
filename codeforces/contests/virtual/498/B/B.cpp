#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    map<int, vector<int>> idx;
    int m = 5000, M = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        idx[x].push_back(i);
        m = min(m, x);
        M = max(M, x);
    }
    int ans = 0;
    vector<int> vec(n);
    for (int i = M; i >= m; i--) {
        if (!idx[i].size())continue;
        for (auto& j : idx[i]) {
            if (k) {
                vec[j] = 1;
                ans += i;
                k--;
            }
        }
    }
    int last = -1;
    vector<int> cnt;
    for (int i = 0; i < n; i++) {
        if (vec[i]) {
            cnt.push_back(i - last);
            last = i;
        }
        if (i == n - 1 && !vec[i]) cnt.back() += i - last;
    }
    cout << ans << endl;
    for (auto& c : cnt)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}