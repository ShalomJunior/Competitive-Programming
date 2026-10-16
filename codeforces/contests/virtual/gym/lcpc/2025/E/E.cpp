#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 55;
vector<int> m(N + 1);
void solve() {
    int x;
    cin >> x;
    int k = N;
    while ((x & m[k]) == 0) k--;
    int ans = 0;
    for (int j = k - 1; j >= 0; j--) {
        if ((x & m[j]) == 0) {
            ans += m[j];
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    m[0] = 1;
    for (int j = 1; j < N; j++) m[j] = m[j - 1] * 2;
    int t; cin >> t;
    while (t--) solve();
}