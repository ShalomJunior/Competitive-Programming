#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    n = n * (n + 1) / 2;
    cout << (n & 1 ? 1 : 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}