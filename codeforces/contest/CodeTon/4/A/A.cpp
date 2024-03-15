#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    bool ans = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans |= v[i] <= i + 1;
    }
    cout << ((ans) ? "YES" : "NO") << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}