#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int q; cin >> q;
    vector<int> a(N);
    while (q--) {
        int t, v; cin >> t >> v;
        if (t == 1) a[v]++;
        else {
            int ans = 0;
            for (int i = N - 1; i >= 0; i--) {
                int need = (v - ans) / (1 << i);
                ans += min(need, a[i]) * (1 << i);
            }
            cout << (ans == v ? "YES" : "NO") << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
