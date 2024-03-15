#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(3);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    cout << (a[1] + a[2] >= 10 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}