#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, t; cin >> n >> t;
    vector<int> a(n), b(n);
    for (auto& c : a)cin >> c;
    for (auto& c : b)cin >> c;

    int idx = -2, curr = -2;
    for (int i = 0; i < n; i++) {
        if (i + a[i] <= t && b[i] > curr) {
            idx = i; curr = b[i];
        }
    }
    cout << idx + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}