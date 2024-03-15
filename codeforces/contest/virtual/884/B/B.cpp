#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n < 3) {
        if (n == 1) cout << "1\n";
        else cout << "1 2\n";
        return;
    }
    vector<int> a(n);
    a[0] = 2, a[(n - 1) / 2] = 1, a[n - 1] = 3;
    for (int v = 3, i = 0; i < n; i++) {
        if (!a[i]) a[i] = ++v;
    }
    for (auto& c : a)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}