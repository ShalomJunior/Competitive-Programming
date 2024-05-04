#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int go(int n, int m, int cnt) {
    if (n > m) return INF;
    else if (n == m) return cnt;
    return min(go(n * 2, m, cnt + 1), go(n * 3, m, cnt + 1));
}

void solve() {
    int n, m; cin >> n >> m;
    int ans = go(n, m, 0);
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}