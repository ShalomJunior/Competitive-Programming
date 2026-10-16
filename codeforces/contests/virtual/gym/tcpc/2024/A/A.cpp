#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mn = 200;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mn = min(mn, x);
    }
    cout << mn - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}