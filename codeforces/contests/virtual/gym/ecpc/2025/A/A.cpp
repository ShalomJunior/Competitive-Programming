#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Info {
    string city;
    string skill;
    string sys;
    string pers;
    int p;
    int r;
    int m;
};

void solve() {
    int n;
    cin >> n;
    vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].city >> a[i].skill >> a[i].sys >> a[i].pers >> a[i].p >> a[i].r >> a[i].m;
    }
    int ans = -1;
    for (int i = 1; i < n; i++) {
        if (a[i].city == a[0].city && a[i].skill != a[0].skill && a[i].sys == a[0].sys) {
            int curr = a[i].p * a[0].p + a[i].r * a[0].r + a[i].m * a[0].m;
            if (a[i].pers != a[0].pers) curr += 1000;
            ans = max(ans, curr);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}