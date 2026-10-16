#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (b == 0) {
        cout << (a & 1 ? "NO" : "YES");
    }
    else {
        if (b & 1) {
            if (a >= 2) {
                a -= 2;
                cout << (a & 1 ? "NO" : "YES");
            }
            else {
                cout << "NO";
            }
        }
        else {
            cout << (a & 1 ? "NO" : "YES");
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