#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto& c : a) cin >> c, cnt[c]++;
    vector<int> pref(n), suff(n);
    for (int i = 0, sum = 0; i < n; i++) {
        sum += a[i];
        pref[i] = sum;
    }
    for (int i = n - 1, sum = 0; i >= 0; i--) {
        sum += a[i];
        suff[i] = sum;
    }
    vector<int> id;
    for (int i = 0; i < n; i++) {
        int d = 0;
        d += (i ? pref[i - 1] : 0);
        d += (i + 1 < n ? suff[i + 1] : 0);
        if (d % 2 == 0) {
            int x = d / 2;
            if (x != a[i] && cnt[x] || x == a[i] && cnt[x] > 1) id.push_back(i);
        }
    }
    cout << id.size() << endl;
    for (auto& c : id) cout << c + 1 << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}