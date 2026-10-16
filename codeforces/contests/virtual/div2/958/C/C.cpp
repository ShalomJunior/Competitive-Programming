#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 60;
void solve() {
    int n;
    cin >> n;
    vector<int> m;
    for (int j = N; j >= 0; j--) {
        int mask = 1LL << j;
        if (n & mask)
            m.push_back(mask);
    }
    int z = m.size();
    if (z == 1) {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }
    vector<int> ans(2);
    for (int i = 0; i < z; i++) {
        if (i & 1) {
            ans[0] |= m[i];
        }
        else {
            ans[1] |= m[i];
        }
    }
    while (ans.back() != n) {
        int add = 0;
        for (int j = 0; j < N; j++) {
            int mask = 1LL << j;
            if (n & mask && !(ans.back() & mask))
                add |= mask;
        }
        for (int j = N; j >= 0 && add <= ans.back(); j--) {
            int mask = 1LL << j;
            if (n & mask) add |= mask;
        }
        ans.push_back(add);
    }
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}