#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(k), t(k);
    for (auto& c : a) cin >> c;
    for (auto& c : t) cin >> c;
    vector<int> x(n, INF), y(n, INF);
    for (int i = 0; i < k; i++) {
        int j = a[i] - 1;
        x[j] = y[j] = t[i];
    }
    for (int i = 0; i < n; i++) {
        x[i] = min(x[i], i - 1 < 0 ? INF : x[i - 1] + 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        y[i] = min(y[i], i + 1 < n ? y[i + 1] + 1 : INF);
    }
    for (int i = 0; i < n; i++) {
        cout << min(x[i], y[i]) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}