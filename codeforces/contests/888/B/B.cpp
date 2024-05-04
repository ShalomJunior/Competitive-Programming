#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    bool ans = true;
    for (int i = 0; i < n; i++) {
        ans &= ~((a[i] & 1) ^ (b[i] & 1));
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}