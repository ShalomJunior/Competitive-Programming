#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto& c : a)cin >> c;
    sort(a.begin(), a.end());
    if (a[0] != 1) { cout << "NO" << endl; return; }
    long long up = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > up) { cout << "NO" << endl; return; }
        else up += a[i];
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}