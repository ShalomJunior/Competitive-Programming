#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int K = a[0];
    sort(a.begin(), a.end());
    vector<int> b(m);
    for (auto& c : b) cin >> c;
    b.push_back(-1);
    sort(b.begin(), b.end());
    for (int k = 1; k <= m; k++) {
        int r = 0;
        int lim = m;
        for (int i = k; i <= m; i += k) {
            if (b[i] <= K) {
                r++;
            }
            else {
                int j = upper_bound(b.begin() + i - k + 1, b.begin() + i + 1, K) - b.begin();
                int need = k - (j - (i - k + 1));
                int L = b[lim - need + 1];
                assert(L > K);
                auto it = lower_bound(a.begin(), a.end(), L);
                j = it - a.begin();
                r += n - j + 1;
                lim -= need;
            }
        }
        cout << r << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}