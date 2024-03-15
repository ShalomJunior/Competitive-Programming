#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    queue<int> q;
    q.push(1);
    int sm = 0;
    for (int i = 2; i <= m; i++) {
        sm += q.back();
        q.push(sm);
    }

    for (int i = m + 1; i <= n; i++) {
        sm += q.back();
        sm %= MOD;
        q.push(sm);
        sm -= q.front();
        sm += MOD; sm %= MOD;
        q.pop();
    }
    cout << q.back() << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}