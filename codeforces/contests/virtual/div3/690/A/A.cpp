#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    for (int i = 0; i < n / 2; i++) {
        cout << a[i] << " " << a[n - 1 - i] << " ";
    }
    if (n & 1) cout << a[n / 2];
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}