#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    multiset<int> l, r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r.insert(a[i] + i);
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int curr = a[i];
        r.erase(r.find(a[i] + i));
        if (l.size()) curr = max(curr, *prev(l.end()) + i);
        if (r.size()) curr = max(curr, *prev(r.end()) - i);
        curr = max(curr, 0);
        ans = min(ans, curr);
        l.insert(a[i] - i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
