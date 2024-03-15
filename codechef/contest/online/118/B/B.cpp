#include <bits/stdc++.h>
using namespace std;

void solve() {
    double p, l;
    cin >> p >> l;
    cout << (l / p * 100 >= 75 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}