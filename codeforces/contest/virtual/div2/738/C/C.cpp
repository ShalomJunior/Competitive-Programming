#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (a[n - 1] == 0) {
        for (int i = 1; i <= n + 1; i++) cout << i << " ";
        cout << endl;
        return;
    }
    if (a[0] == 1) {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0 && a[i + 1] == 1) {
            for (int j = 1; j <= i + 1; j++) cout << j << " ";
            cout << n + 1 << " ";
            for (int j = i + 2; j <= n; j++) cout << j << " ";
            cout << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}