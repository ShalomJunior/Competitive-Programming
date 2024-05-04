#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    while (true) {
        string s = to_string(n);
        int sum = 0;
        for (auto& c : s) sum += c - '0';
        if (sum % 4 == 0) {
            cout << n << endl;
            return;
        }
        n++;
    }
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}