#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 1; i < n; i++) cin >> x[i];
    vector<int> a(n);
    a[0] = 501;
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + x[i];
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
