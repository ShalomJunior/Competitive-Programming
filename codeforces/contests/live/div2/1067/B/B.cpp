#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int z = 2 * n;
    map<int, int> h;
    for (int i = 0; i < z; i++) {
        int x;
        cin >> x;
        h[x]++;
    }
    int ans = 0;
    int sup = 0;
    int ones = 0;
    for (auto& [k, v] : h) {
        int x = v / 2;
        int y = v - x;
        if (x & 1) ans++;
        if (y & 1) ans++;
        sup += v % 4 == 0;
        ones += v == 1;
    }
    int add = (sup / 2) * 4;
    if (sup & 1 && ones) ans += 2;
    cout << ans + add << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
