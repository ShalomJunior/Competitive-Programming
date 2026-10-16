#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s += a;
    }
    cout << (n * x == s ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}