#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n;
    if (n & 1) l++;
    while (l < r) cout << l++ << " " << r-- << " ";
    if (n & 1) cout << 1;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}