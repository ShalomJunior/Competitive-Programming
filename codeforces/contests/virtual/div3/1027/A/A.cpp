#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = stoi(s);
    int x = sqrt(n);
    if (x * x == n) {
        cout << 1 << " " << x - 1;
    }
    else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}