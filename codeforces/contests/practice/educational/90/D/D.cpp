#include <bits/stdc++.h>
#define int long long
using namespace std;

int best(vector<int> a) {
    int ans = 0;
    multiset<int> ms(a.begin(), a.end());
    int last = 0;
    for (int i = 0; i < a.size(); i++) {
        ans = max(ans, *prev(ms.end()) - (i ? a[i - 1] : 0));
        ms.erase(ms.find(a[i]));
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0) x += a[i];
    }
    int ans = x;
    vector<int> e;
    for (int i = 0; i + 1 < n; i += 2) {
        int add = a[i + 1] - a[i];
        e.push_back(add + (e.empty() ? 0 : e.back()));
    }
    vector<int> o;
    for (int i = 1; i + 1 < n; i += 2) {
        int add = a[i] - a[i + 1];
        o.push_back(add + (o.empty() ? 0 : o.back()));
    }
    ans += max({ best(e), best(o), 0LL });
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
