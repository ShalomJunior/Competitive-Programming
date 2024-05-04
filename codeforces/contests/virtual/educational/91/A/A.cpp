#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (a[i] < a[j] && a[j] > a[k]) {
                cout << "YES" << endl;
                cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                return;
            }
        }
        if (a[j] < a[i])i = j;
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
