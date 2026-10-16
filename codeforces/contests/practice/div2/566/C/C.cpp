#include <bits/stdc++.h>
#define int long long
using namespace std;

const int T = 100;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (auto& c : t) cin >> c;
    vector<int> cnt(T + 1);
    for (int i = 0, s = 0; i < n; i++) {
        int lim = m - t[i];
        int k = 0;
        int should = s - lim;
        for (int j = T; j > 0 && should > 0; j--) {
            int tot = cnt[j] * j;
            if (should >= tot) {
                should -= tot;
                k += cnt[j];
            }
            else {
                int q = (should + j - 1) / j;
                k += q;
                break;
            }
        }
        cout << k << " ";
        s += t[i];
        cnt[t[i]]++;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
