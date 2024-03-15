#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N = 10;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<unordered_map<int, int>> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= N; j++) {
            int r = (a[i] * (int)pow(10, j)) % k;
            cnt[j][r]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int r = k - a[i] % k; r %= k;
        int j = to_string(a[i]).length();
        int c = cnt[j][r];
        if ((a[i] * (int)pow(10, j)) % k == r) c--;
        ans += c;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}