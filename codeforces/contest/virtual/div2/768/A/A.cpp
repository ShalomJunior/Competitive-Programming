#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) swap(a[i], b[i]);
    }
    int x = *max_element(a.begin(), a.end());
    int y = *max_element(b.begin(), b.end());
    cout << x * y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}