#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n & 1) {
        for (int i = 0; i < n; i += 2) {
            int d = s[i] - '0';
            if (d & 1) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
    }
    else {
        for (int i = 1; i < n; i += 2) {
            int d = s[i] - '0';
            if (d % 2 == 0) {
                cout << 2 << endl;
                return;
            }
        }
        cout << 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}