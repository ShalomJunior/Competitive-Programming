#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((2 * b - c > 0 && (2 * b - c) % a == 0)) cout << "YES";
    else if (((a + c) % (2 * b)) == 0) cout << "YES";
    else if ((2 * b - a) > 0 && ((2 * b - a) % c) == 0) cout << "YES";
    else cout << "NO";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}