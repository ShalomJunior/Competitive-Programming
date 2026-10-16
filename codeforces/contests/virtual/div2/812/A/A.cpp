#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a == 0 ? y.push_back(b) : x.push_back(a);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int s = 0;
    if (!x.empty()) {
        if (x[0] < 0) s += abs(x[0]);
        if (x.back() > 0) s += x.back();
    }
    if (!y.empty()) {
        if (y[0] < 0) s += abs(y[0]);
        if (y.back() > 0) s += y.back();
    }
    cout << 2 * s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}