#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int L = 0, R = 0;
    set<int> f;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t < 0) { (t == -1) ? L++ : R++; }
        else f.insert(t);
    }

    vector<int> p(f.begin(), f.end());
    int s = (int)p.size();
    int ans = 0;
    for (int i = 0; i < s; i++) {
        int curr = 1;
        curr += min(p[i] - 1, L + i);
        curr += min(m - p[i], R + s - 1 - i);
        ans = max(ans, curr);
    }

    ans = max(ans, min(R + s, m));
    ans = max(ans, min(L + s, m));

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}