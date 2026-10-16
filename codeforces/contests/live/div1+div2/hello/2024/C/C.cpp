#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        int f = x.empty() ? INF : x.back();
        int s = y.empty() ? INF : y.back();
        if (a[i] <= min(f, s)) {
            f < s ? x.push_back(a[i]) : y.push_back(a[i]);
        }
        else if (a[i] > max(f, s)) {
            f < s ? x.push_back(a[i]) : y.push_back(a[i]);
        }
        else {
            f < s ? y.push_back(a[i]) : x.push_back(a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < (int)x.size() - 1; i++) {
        if (x[i] < x[i + 1]) ans++;
    }
    for (int i = 0; i < (int)y.size() - 1; i++) {
        if (y[i] < y[i + 1]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}