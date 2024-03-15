#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n; --n;
    while (__builtin_popcount(n) != 1) {
        cout << n << " ";
        n--;
    }
    cout << n << " " << 0 << " ";
    for (int j = 1; j < n; j++) cout << j << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}