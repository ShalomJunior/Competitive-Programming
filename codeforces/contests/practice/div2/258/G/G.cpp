#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = '#' + s;
    vector<int> m(N, 1);
    for (int j = 1; j < N; j++) {
        m[j] = m[j - 1] * 2;
    }
    vector<int> h(1 << N, -1);
    h[0] = 0;
    int ans = 0;
    int mask = 0;
    for (int i = 1; i <= n; i++) {
        int k = s[i] - 'a';
        mask ^= m[k];
        for (int j = 0; j < N; j++) {
            int nmask = mask ^ m[j];
            if (h[nmask] != -1) {
                ans = max(ans, i - h[nmask]);
            }
        }
        if (h[mask] != -1) {
            ans = max(ans, i - h[mask]);
        }
        else {
            h[mask] = i;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
