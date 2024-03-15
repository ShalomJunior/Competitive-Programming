#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n & 1) cout << "Bob";
    else {
        if (__builtin_popcount(n) > 1) cout << "Alice";
        else {
            int cnt = 0;
            while (n > 2) {
                n >>= 1;
                cnt++;
            }
            cout << (cnt & 1 ? "Alice" : "Bob");
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}