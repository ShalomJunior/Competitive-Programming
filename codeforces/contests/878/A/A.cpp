#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s, ans = "";
    cin >> n >> s;
    queue<char> q;
    for (auto& c : s)q.push(c);
    while (!q.empty()) {
        char c = q.front(); q.pop();
        ans += c;
        while (q.front() != c)q.pop();
        q.pop();
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}