#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, c, n;
    cin >> a >> b >> c >> n;
    int sum = a + b + c + n;
    if (sum % 3 || max({ a, b, c }) > sum / 3) cout << "NO";
    else cout << "YES";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}