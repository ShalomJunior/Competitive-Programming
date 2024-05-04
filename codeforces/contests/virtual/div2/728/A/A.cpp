#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for (int i = 0; i < n - 1; i += 2) swap(a[i], a[i + 1]);
    if (n & 1) swap(a[n - 2], a[n - 1]);
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}