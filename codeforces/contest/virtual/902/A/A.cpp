#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        cnt += x;
    }
    cout << -cnt << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}