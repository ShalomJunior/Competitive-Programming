#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a == i) cnt++;
    }
    cout << (cnt + 1) / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}