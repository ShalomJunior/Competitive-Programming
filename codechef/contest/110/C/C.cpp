#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, k;
    cin >> n >> x >> k;
    int a = x % k, b = (n - x) % k;
    cout << abs(a - b) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}