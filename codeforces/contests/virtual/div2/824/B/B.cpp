#include <bits/stdc++.h>
using namespace std;

int get(int n, int x) {
    int m = 2 * x - 1;
    int q = (n + m - 1) / m;
    return q - 1;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (2 * a[0] <= a[i])ans += get(a[i], a[0]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}