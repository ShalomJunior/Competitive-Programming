#include <bits/stdc++.h>
using namespace std;

const int N = 4;
void solve() {
    int ans = 0;
    int last = 1;
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        int d = c - '0';
        if (d == 0) d = 10;
        ans += abs(d - last);
        last = d;
    }
    cout << ans + 4 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}