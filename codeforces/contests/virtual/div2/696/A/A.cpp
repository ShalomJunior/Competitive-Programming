#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string b;
    cin >> n >> b;
    string a = "1";
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == b[i - 1]) {
            if (a[i - 1] == '0') {
                a += '1';
            }
            else {
                a += (b[i] == '0' ? '1' : '0');
            }
        }
        else {
            a += (b[i] == '0' ? '0' : '1');
        }
    }
    cout << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}