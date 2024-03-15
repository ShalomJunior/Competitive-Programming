#include <bits/stdc++.h>

using namespace std;

int mult(vector<int>& a, int x) {
    int n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n;i++) {
        b[i] = a[i] ^ x;
    }

    int ans = b[0];
    for (int i = 1; i < n; i++) {
        ans ^= b[i];
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v) cin >> c;

    for (int i = 0; i <= 1 << 8; i++) {
        int ans = mult(v, i);
        if (!ans) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}