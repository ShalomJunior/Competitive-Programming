#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 3) {
        cout << -1 << endl;
        return;
    }
    if (n & 1) {
        cout << string(n - 5, '3') << "36366";
    }
    else {
        cout << string(n - 2, '3') << "66";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}