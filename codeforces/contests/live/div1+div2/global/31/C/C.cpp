#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
void solve() {
    int n, k;
    cin >> n >> k;
    multiset<int> ans;
    for (int i = 0; i < k; i++) ans.insert(0);
    for (int i = N; i >= 0; i--) {
        int m = 0;
        int mask = 1 << i;
        if (n & mask) {
            m = k & 1 ? k : k - 1;
        }
        else {
            m = k & 1 ? k - 1 : k;
        }
        int u = 0;
        int j = -1;
        vector<int> nxt;
        for (auto& c : ans) {
            if (m - u > 0) {
                int nc = c | mask;
                if (nc <= n) {
                    nxt.push_back(nc);
                    j = nxt.size() - 1;
                    u++;
                }
                else {
                    nxt.push_back(c);
                }
            }
            else {
                nxt.push_back(c);
            }
        }
        if (m % 2 != u % 2) {
            assert(j != -1);
            for (int l = 0; l < k; l++) {
                if ((nxt[l] & mask) && nxt[j] < nxt[l]) {
                    j = l;
                }
            }
            nxt[j] ^= mask;
        }
        ans = multiset<int>(nxt.begin(), nxt.end());
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}