#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;
    if (n == 0) {
        cout << -1 << " " << 1;
    }
    else {
        cout << -n + 1 << " " << n;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}