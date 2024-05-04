#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;
    int j = 1;
    while (n % j == 0) j++;
    cout << j - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}