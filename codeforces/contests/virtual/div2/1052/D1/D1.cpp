#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    int m = 1;
    while (m <= n) m <<= 1;
    return m;
}
void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i] == -1) {
            ans[i] = f(i) - 1 - i;
            ans[ans[i]] = i;
        }
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += (i | ans[i]);
    cout << sum << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
