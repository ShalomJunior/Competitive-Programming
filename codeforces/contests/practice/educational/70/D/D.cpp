#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    return n * (n - 1) / 2;
}

void solve() {
    int n;
    cin >> n;
    int j = 1;
    while (f(j + 1) <= n) j++;
    int rem = n - f(j);
    cout << "133" << string(rem, '7') << string(j - 2, '3') << "7" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
