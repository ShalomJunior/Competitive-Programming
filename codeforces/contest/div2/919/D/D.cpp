#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 2e18;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> len(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            len[i] = (i ? len[i - 1] : 0);
            len[i]++;
            v[i] = x;
        }
        else {
            if (i == 1) v[i] = v[i - 1];
            if (x + 1 <= INF / len[i - 1])
                len[i] = len[i - 1] * (x + 1);
            else len[i] = INF;
        }
    }
    while (q--) {
        int p; cin >> p;
        while (true) {
            auto it = lower_bound(len.begin(), len.end(), p);
            int j = it - len.begin();
            if (j == 0 || len[j] - len[j - 1] == 1) {
                cout << v[j] << " ";
                break;
            }
            p %= len[j - 1];
            if (p == 0) p = len[j - 1];
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}