#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int i = 1, j = n;
    while (i < j) {
        cout << i++ << " " << j-- << " ";
    }
    if (i == j) cout << i;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
