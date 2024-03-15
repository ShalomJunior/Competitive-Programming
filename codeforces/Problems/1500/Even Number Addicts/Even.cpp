#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N][N][2][2];

int go(int odd, int even, int who, int a, int b) {
    if (!odd & !even) return a;
    int& ans = dp[odd][even][who][(who) ? b : a];
    if (ans != -1) return ans;
    if (who) {
        bool can = false;
        if (even) can |= go(odd, even - 1, 0, a, b);
        if (odd) can |= go(odd - 1, even, 0, a, (b + 1) % 2);
        ans = (can) ? 1 : 0;
    }
    else {
        bool can = false;
        if (even) can |= (!go(odd, even - 1, 1, a, b));
        if (odd) can |= (!go(odd - 1, even, 1, (a + 1) % 2, b));
        ans = (can) ? 0 : 1;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a & 1)odd++;
        else even++;
    }
    memset(dp, -1, sizeof(dp));
    cout << ((go(odd, even, 0, 0, 0) ? "Bob" : "Alice")) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}