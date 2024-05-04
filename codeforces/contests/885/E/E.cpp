#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    n--;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0 && i < n / i) {
            cout << i << endl;
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}