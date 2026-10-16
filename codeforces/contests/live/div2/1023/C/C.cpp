#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e13;
int best(vector<int>& a, int n) {
    int best = a[0];
    int curr = 0;
    for (int i = 1; i <= n; i++) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
    }
    return best;
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "#" + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (s[i] == '0') {
            a[i] = -INF;
        }
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> L(n + 1);
    for (int i = 1; i <= n; i++) {
        L[i] = min(L[i - 1], pref[i]);
    }
    vector<int> R(n + 2, -1e18);
    for (int i = n; i > 0; i--) {
        R[i] = max(R[i + 1], pref[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == -INF) {
            int l = max(pref[i - 1] - (i - 2 >= 0 ? L[i - 2] : 0), 0LL);
            int r = max(R[i + 1] - pref[i], 0LL);
            int need = k - (l + r);
            a[i] = need;
            break;
        }
    }
    if (best(a, n) == k) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
