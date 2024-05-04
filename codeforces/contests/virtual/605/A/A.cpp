#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    vector<int> d = { -1, 0, 1 };
    long long ans = 5e18;
    for (int i : d) {
        for (int j : d) {
            for (int k : d) {
                long long x = a + i, y = b + j, z = c + k;
                ans = min(ans, abs(x - y) + abs(x - z) + abs(y - z));
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}