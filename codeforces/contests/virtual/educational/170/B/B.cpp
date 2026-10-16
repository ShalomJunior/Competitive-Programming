#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;
const int MOD = 1e9 + 7;
vector<int> p(N, 1);

void solve() {
    int t;
    cin >> t;
    vector<int> n(t);
    for (auto& c : n) cin >> c;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        cout << p[x] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * 2 % MOD;
    solve();
}
