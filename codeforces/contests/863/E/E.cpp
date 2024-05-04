#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 17;
vector<int> p(N + 1);
void solve() {
    int k; cin >> k;
    auto go = [&](int mid) {
        string s = to_string(mid);
        int n = s.length();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += 8 * p[i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = (i ? 0 : 1); j < s[i] - '0'; j++) {
                if (j == 4) continue;
                ans += p[n - (i + 1)];
            }
            if (s[i] == '4') return ans;
        }
        return ans + 1;
        };
    int L = 1, R = 1e15;
    while (L < R) {
        int mid = (L + R) / 2;
        int id = go(mid);
        if (id < k) L = mid + 1;
        else R = mid;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    p[0] = 1;
    for (int i = 1; i <= N; i++) p[i] = p[i - 1] * 9;
    int t; cin >> t;
    while (t--) solve();
}