#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long s = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        ans = min(ans, s);
    }
    cout << -ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}