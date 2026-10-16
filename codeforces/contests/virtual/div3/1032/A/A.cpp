#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int x = abs(a[0] - s) + abs(a[0] - a.back());
    int y = abs(s - a.back()) + abs(a.back() - a[0]);
    cout << min(x, y) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}