#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int s = n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i > 1)s = min(s, i);
            if (n / i > 1)s = min(s, n / i);
        }
    }
    int g = n / s;
    cout << g << " " << n - g << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}