#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    cout << ((n + 1) % 3 == 0 || (n - 1) % 3 == 0 ? "First" : "Second") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
