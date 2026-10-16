#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto& c : a) cin >> c;
    int cnt = count(a.begin(), a.end(), 1);
    cout << cnt % 2 << " ";
    cout << (cnt <= n ? cnt : 2 * n - cnt) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
