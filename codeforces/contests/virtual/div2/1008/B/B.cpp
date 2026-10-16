#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    if (k & 1) {
        for (int i = 0; i < n; i++) ans[i] = n;
        ans[n - 1] = n - 1;
    }
    else {
        for (int i = 0; i < n; i++) ans[i] = n - 1;
        ans[n - 2] = n;
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}