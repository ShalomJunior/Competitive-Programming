#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int x = n - k + 1;
    int r = k % 4;
    if (r == 0) {
        cout << "YES";
    }
    else if (r == 1) {
        cout << (x & 1 ? "NO" : "YES");
    }
    else if (r == 2) {
        cout << "NO";
    }
    else if (r == 3) {
        cout << (x & 1 ? "YES" : "NO");
    }
    else {}
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}