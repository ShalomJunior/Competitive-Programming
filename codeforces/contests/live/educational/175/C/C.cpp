#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto b = a;
    int L = 0;
    int R = INF;
    auto go = [&](int mid) {
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (a[i] > mid) {
                    if (cnt) {
                        res++;
                        cnt = 0;
                    }
                }
            }
            else {
                if (cnt == 0) {
                    if (a[i] > mid) {
                        cnt++;
                    }
                }
            }
        }
        if (cnt) res++;
        return res;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) <= k ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
