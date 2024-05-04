#include <bits/stdc++.h>
using namespace std;

const string match = "2020";
void solve() {
    int n; cin >> n;
    long long ans = 0;
    do {
        int sub = n - n % 10;
        ans += sub;
        n -= sub;
        n += sub / 10;
    } while (n >= 10);
    cout << ans + n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}