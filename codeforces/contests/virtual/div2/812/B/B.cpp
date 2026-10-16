#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<bool> L(n + 2, true);
    for (int i = 1; i <= n; i++) {
        L[i] = (L[i - 1] && a[i - 1] <= a[i]);
    }
    vector<bool> R(n + 2, true);
    for (int i = n; i > 0; i--) {
        R[i] = (R[i + 1] && a[i] >= a[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        if (L[i] && R[i]) {
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