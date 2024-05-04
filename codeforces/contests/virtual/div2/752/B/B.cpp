#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (n % 2 == 0) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] >= a[i + 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}