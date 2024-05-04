#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    set<int> s;
    map<int, map<int, int>> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        int cnt = 0;
        while (true) {
            s.insert(x);
            h[a[i]][x] = cnt;
            if (!x) break;
            x /= 2;
            cnt++;
        }
    }
    int ans = INF;
    for (auto it = s.begin(); it != s.end(); it++) {
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            if (h[a[i]].count(*it)) {
                vec.push_back(h[a[i]][*it]);
            }
        }
        sort(vec.begin(), vec.end());
        int m = vec.size();
        if (m < k) continue;
        int cnt = 0;
        for (int i = 0; i < k; i++) cnt += vec[i];
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}