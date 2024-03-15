#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(3);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x % 3]++;
    }
    int q = n / 3, ans = 0;
    for (auto k : { 1, 2 }) {
        for (int i = 0; i < 3; i++) {
            if (a[i] > q) {
                int sup = a[i] - q;
                a[(i + 1) % 3] += sup;
                ans += sup;
                a[i] = q;
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