#include <bits/stdc++.h>
using namespace std;

const int N = 31;
void solve() {
    int n, x;
    cin >> n >> x;
    int j = 0;
    while (x & (1 << j)) j++;
    int lim = 1 << j;
    vector<int> ans(n);
    int X = 0;
    for (int i = 0; i < n && i < lim; i++) {
        ans[i] = i;
        X |= ans[i];
    }
    if (X != x) ans[n - 1] = x;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}