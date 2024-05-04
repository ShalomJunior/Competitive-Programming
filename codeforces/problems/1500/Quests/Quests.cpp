#include <bits/stdc++.h>
#define int long long

using namespace std;
const int INF = 1e7;

int calc(vector<int>& pref, int d, int k) {
    int n = (int)pref.size();
    int coins = (d / (k + 1)) * pref[min(k + 1, n) - 1];
    if (d % (k + 1)) coins += pref[min(n, d % (k + 1)) - 1];
    return coins;
}

void solve() {
    int n, c, d; cin >> n >> c >> d;
    vector<int> a(n);
    for (auto& c : a)cin >> c;

    sort(a.rbegin(), a.rend());

    vector<int> pref(n);
    for (int i = 0;i < n; i++) {
        pref[i] = a[i] + ((i) ? pref[i - 1] : 0);
    }

    if (a[0] * d < c) { cout << "Impossible" << endl; return; }

    int m = min(n, d);
    if (pref[m - 1] >= c) { cout << "Infinity" << endl; return; }

    int L = 0, R = INF;
    while (L + 1 < R) {
        int k = (L + R) / 2;
        int coins = calc(pref, d, k);
        (coins < c) ? R = k - 1 : L = k;
    }
    cout << ((calc(pref, d, R) < c) ? L : R) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}