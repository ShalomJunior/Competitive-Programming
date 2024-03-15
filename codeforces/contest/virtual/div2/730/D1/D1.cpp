#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int q = (i ? i ^ (i - 1) : 0);
        cout << q << endl;
        cout.flush();
        int r; cin >> r;
        if (r == 1) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}