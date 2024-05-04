#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    if (a < b) swap(a, b);
    long long g = a - b;
    cout << g << " " << min(b % g, g - b % g) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}