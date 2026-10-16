#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            i & 1 ? s++ : s--;
        }
        if (s == -2 || s == 2) s = 0;
    }
    if (s == -1) {
        cout << "Ajisai";
    }
    else if (s == 0) {
        cout << "Tie";
    }
    else {
        cout << "Mai";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
