#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int s = a + b + c;
    if (s % 3) {
        cout << "NO";
    }
    else {
        int k = s / 3;
        cout << (k >= max(a, b) ? "YES" : "NO");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
