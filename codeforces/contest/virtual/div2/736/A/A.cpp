#include <bits/stdc++.h>
using namespace std;

void solve() {
    int p; cin >> p;
    cout << 2 << " " << (p == 5 ? 4 : p / 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}