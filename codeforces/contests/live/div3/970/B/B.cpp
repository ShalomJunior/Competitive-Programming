#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int m = sqrt(n);
    if (m * m != n) {
        cout << "NO" << endl;
        return;
    }
    int a[n][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
