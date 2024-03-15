#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;  cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<long long> pre(n);
    pre[1] = 1;
    for (int i = 1; i < n - 1; i++) {
        pre[i + 1] = pre[i];
        if (a[i + 1] - a[i] < a[i] - a[i - 1]) {
            pre[i + 1]++;
        }
        else {
            pre[i + 1] += a[i + 1] - a[i];
        }
    }
    vector<long long> suf(n);
    suf[n - 2] = 1;
    for (int i = n - 2; i > 0; i--) {
        suf[i - 1] = suf[i];
        if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
            suf[i - 1]++;
        }
        else {
            suf[i - 1] += a[i] - a[i - 1];
        }
    }
    int m; cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (x < y) {
            cout << pre[y] - pre[x] << endl;
        }
        else {
            cout << suf[y] - suf[x] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
