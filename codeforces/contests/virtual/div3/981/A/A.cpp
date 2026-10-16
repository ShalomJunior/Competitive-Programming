#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int j = 0;
    int x = 0;
    while (abs(x) <= n) {
        j++;
        int m = 2 * j - 1;
        x += j & 1 ? m : -m;
    }
    cout << (j & 1 ? "Sakurako" : "Kosuke") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}