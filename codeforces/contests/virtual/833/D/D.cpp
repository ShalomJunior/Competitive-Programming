#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    cout << 1 + a + 2 * b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}