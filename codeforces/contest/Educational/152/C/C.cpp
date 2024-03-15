#include <bits/stdc++.h>
#define Mine pair<int,int> 
#define F first
#define S second
using namespace std;

void solve() {
    int n, m; string s;
    cin >> n >> m >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] - '0') + (i ? a[i - 1] : 0);
    }
    set<Mine> done;
    int ans = 0, plus = 0;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; --l, --r;
        if (done.count({ l, r }))continue;
        int one = a[r] - (l ? a[l - 1] : 0);
        int zero = r - l + 1 - one;
        int start = l ? a[l - 1] : 0;
        if (a[r] == a[r - one] + one) plus = 1;
        else if (start != a[l + zero - 1]) ans++;
    }
    cout << ans + plus << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}