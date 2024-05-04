#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v) cin >> c;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(v[i], v[j]) <= 2) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;

}

int main() {
    int t; cin >> t;
    while (t--)solve();
}