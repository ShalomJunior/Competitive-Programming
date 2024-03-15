#include <bits/stdc++.h>
using namespace std;

void solve() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a * b >= c) cout << "Yes";
    else cout << "No";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}