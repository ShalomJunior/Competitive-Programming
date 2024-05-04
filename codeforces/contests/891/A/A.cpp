#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a & 1 ? odd++ : even++;
    }
    cout << (odd & 1 ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}