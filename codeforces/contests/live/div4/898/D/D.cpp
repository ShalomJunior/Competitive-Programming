#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') q.push(i);
    }
    if (q.empty()) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    while (!q.empty()) {
        int x = q.front(); ans++;
        while (!q.empty() && q.front() <= x + k - 1) q.pop();
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}