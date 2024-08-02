#include<bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (auto& c : b) cin >> c;
    vector<int> a(n);
    a[0] = b[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (b[i - 1] & mask) a[i] |= mask;
            if (i < n - 1 && (b[i] & mask)) a[i] |= mask;
        }
        if ((a[i - 1] & a[i]) != b[i - 1]) {
            cout << -1 << endl;
            return;
        }
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}