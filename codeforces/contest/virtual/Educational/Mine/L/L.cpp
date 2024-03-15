#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h; cin >> n >> h;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<int> pre(n); pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    auto it = upper_bound(pre.begin(), pre.end(), h * 60);
    cout << it - pre.begin() << " " << accumulate(pre.begin(), it, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
