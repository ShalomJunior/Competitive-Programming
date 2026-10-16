#include <bits/stdc++.h>
using namespace std;

#define M_PI 3.14159265358979323846

void solve() {
    double n;
    cin >> n;
    double res = (1.0 - 2 / M_PI) * n;
    int ans = round(res);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}