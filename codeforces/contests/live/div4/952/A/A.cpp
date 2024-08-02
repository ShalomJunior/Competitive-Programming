#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    swap(a[0], b[0]);
    cout << a << " " << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
