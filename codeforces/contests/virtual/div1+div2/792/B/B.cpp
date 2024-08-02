#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int k = (c - a) / b;
    while (k * b + a <= c || (k * b + a) % c == 0) k++;
    int x = k * b + a;
    int y = b;
    int z = k * b + a + c;
    cout << x << " " << y << " " << z << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}