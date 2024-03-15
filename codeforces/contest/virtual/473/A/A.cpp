#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    cout << (n & 1 ? "Ehab" : "Mahmoud") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}