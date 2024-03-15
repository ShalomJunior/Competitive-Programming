#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    map<int, vector<int>> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        int cnt = 0;
        while (true) {
            h[x].push_back(cnt);
            if (!x) break;
            x /= 2;
            cnt++;
        }
    }
    int ans = INF;
    for (auto& [key, vec] : h) {
        if (vec.size() < k) continue;
        sort(vec.begin(), vec.end());
        int cnt = accumulate(vec.begin(), vec.begin() + k, 0);
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}