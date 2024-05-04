#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        int mask = 1 << i;
        if ((a & mask) ^ (b & mask)) ans |= mask;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}