#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    if (x * 100 >= n) cout << 0;
    else {
        int r = n - x * 100;
        cout << (r % 100 ? r / 100 + 1 : r / 100);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}