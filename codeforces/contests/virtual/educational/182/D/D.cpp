#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c, c--;
    queue<int> r;
    queue<int> c;
    r.push(0);
    int ans = 0;
    for (int i = 1; i < n; ) {
        if (r.empty()) {
            if (c.empty()) break;
            r = c;
            c = queue<int>();
            ans++;
        }
        r.pop();
        int j = i;
        int last = 0;
        while (j < n && last < a[j]) {
            c.push(a[j]);
            last = a[j];
            j++;
        }
        i = j;
    }
    if (!c.empty()) ans++;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
