#include <bits/stdc++.h>
using namespace std;

set<int> s;
const int N = 1000;
void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt += x;
        if (s.count(cnt)) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i += 2) s.insert(i * i);
    int t; cin >> t;
    while (t--)solve();
}