#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % (k + 1)) {
            b[i] = 1;
            idx.push_back(i);
        }
    }
    int m = idx.size();
    vector<long long> d;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            d.push_back(idx[i] + 1);
        }
        else {
            d.push_back(idx[i] - idx[i - 1]);
        }
    }
    d.push_back(n - idx.back());
    for (int i = 1; i <= n; i++) {
        long long ans = 0;
        for (int j = 0; j + i < d.size(); j++) ans += d[j] * d[j + i];
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}