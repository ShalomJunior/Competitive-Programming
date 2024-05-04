#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> M(n);
    M[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        M[i] = max(M[i + 1], a[i]);
    }
    for (int j = n - 3; j >= 0; j--) {
        if (a[j] > a[j + 1] && M[j + 2] > a[j + 1]) {
            cout << j + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}