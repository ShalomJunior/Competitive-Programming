#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    int ans = n / b;

    cout << ((n % b) ? ++ans : ans) << endl;
}
int main() {
    int t; cin >> t;
    while (t--)solve();
}