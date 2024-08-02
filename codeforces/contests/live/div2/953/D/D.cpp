#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = (i ? pref[i - 1] : 0) + a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    multiset<int> R(a.begin(), a.end());
    set<int> L;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            R.erase(R.find(a[0]));
            cout << (*prev(R.end()) <= a[0] + c ? 0 : 1);
            L.insert(a[0] + c);
        }
        else {
            int l = *prev(L.end());
            int r = R.empty() ? -1 : *prev(R.end());
            if (l < a[i] && a[i] >= r) {
                cout << 0;
            }
            else if (r > a[i]) {
                cout << (pref[i] + c >= r ? i : i + 1);
            }
            else {
                cout << i;
            }
            R.erase(R.find(a[i]));
            L.insert(a[i]);
        }
        cout << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
