#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (n == 3) cout << "1 1 1";
    else if (n == 4) cout << "1 1 2";
    else if (n & 1) {
        cout << 1 << " " << (n - 1) / 2 << " " << (n - 1) / 2;
    }
    else {
        if (n % 4 == 2)
            cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2;
        else {
            if (n % 8 == 0)
                cout << n / 4 << " " << n / 4 << " " << n / 2;
            else
                cout << 4 << " " << (n - 4) / 2 << " " << (n - 4) / 2;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}