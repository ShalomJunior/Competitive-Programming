#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mis = 0;
    int mx = 0;
    for (int i = 1; i < n; i++) {
        mis += (a[i] != a[i - 1] + 1);
        mx = max(mx, a[i] - a[i - 1] - 1);
    }
    if (mis == 0) {
        cout << "YES";
    }
    else if (mis == 1) {
        cout << (mx <= 2 ? "YES" : "NO");
    }
    else if (mis == 2) {
        cout << (mx <= 1 ? "YES" : "NO");
    }
    else {
        cout << "NO";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
