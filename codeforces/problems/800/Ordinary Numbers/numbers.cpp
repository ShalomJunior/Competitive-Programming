#include <bits/stdc++.h>

using namespace std;

int sup(int n) {
    stringstream ss; ss << n;
    int d = ss.str()[0] - '0';
    int val = 0;
    for (int i = 0; i < ss.str().size(); i++)
        val += d * pow(10, i);

    if (val > n) return d - 1;
    else return d;
}

void solve() {
    int n; cin >> n;
    int ans = 9 * floor(log10(n)) + sup(n);
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}