#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;
    long long lim = sqrtl(n);
    while (lim * (lim + 2) > n) lim--;
    while ((lim + 1) * (lim + 3) <= n) lim++;
    if (n & 1) {
        cout << (lim & 1 ? (lim + 1) / 2 : lim / 2);
    }
    else {
        cout << lim / 2;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}