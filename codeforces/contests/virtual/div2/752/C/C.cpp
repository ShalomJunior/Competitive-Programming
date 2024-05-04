#include <bits/stdc++.h>
using namespace std;

const int N = 32;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < min(n, N); i++) {
        bool b = false;
        for (int j = i + 2; j >= 2; j--) {
            b |= (a[i] % j);
        }
        if (!b) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}