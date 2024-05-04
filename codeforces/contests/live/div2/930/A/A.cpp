#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int j = 1;
    while (j * 2 <= n) j *= 2;
    cout << j << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
