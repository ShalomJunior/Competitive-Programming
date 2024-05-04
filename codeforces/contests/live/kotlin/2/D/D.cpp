#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c, c++;
    vector<bool> p(n, true);
    auto x = a;
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        if (x[i] == x[i - 1]) x[i]++;
        else if (x[i] < x[i - 1]) p[i] = false;
    }
    vector<bool> s(n, true);
    auto y = a; y[n - 1]++;
    for (int i = n - 2; i >= 0; i--) {
        s[i] = s[i + 1];
        if (y[i] >= y[i + 1]) s[i] = false;
        else if (y[i] + 1 < y[i + 1]) y[i]++;
    }
    for (int i = 0; i < n; i++) {
        bool l = (i ? p[i - 1] : true);
        bool r = (i == n - 1 ? true : s[i + 1]);
        if (!(l & r)) continue;
        if (i == 0 || i == n - 1 || x[i - 1] < y[i + 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
