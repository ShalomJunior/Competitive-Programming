#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p(n), l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        --l[i], --r[i];
        if (l[i] != -1) p[l[i]] = i;
        if (r[i] != -1) p[r[i]] = i;
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') c[i] = p[i];
        else if (s[i] == 'L') c[i] = l[i];
        else if (s[i] == 'R') c[i] = r[i];
    }
    int ans = 1e7;
    vector<bool> done(n);
    vector<int> v(n);
    done[0] = true;
    for (int i = 0; i < n; i++) {
        if (l[i] != -1 || r[i] != -1) continue;
        int x = i;
        int cnt = 0;
        while (x != 0) {
            if (c[p[x]] != x) cnt++;
            if (done[p[x]]) {
                cnt += v[p[x]];
                v[x] = v[p[x]];
                done[x] = true;
                if (c[p[x]] != x) v[x]++;
                break;
            }
            x = p[x];
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
