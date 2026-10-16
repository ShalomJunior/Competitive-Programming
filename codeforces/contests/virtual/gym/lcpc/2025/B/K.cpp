#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
vector<int> m(N + 1);
bool check(int i, int n) {
    for (int j = 0; j < N; j++) {
        if (i & m[j]) {
            if (!(n & m[j])) return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (!check(i, n)) continue;
        for (int j = 0; j <= n; j++) {
            if (check(j, n) && (i | j) == n) ans++;
        }
    }
    cout << "n = " << n << endl;
    cout << "ans = " << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    m[0] = 1;
    for (int i = 1; i <= N; i++) m[i] = m[i - 1] * 2;
    solve();
}
