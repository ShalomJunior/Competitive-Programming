#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n - 2; i++) {
        int x;
        cin >> x;
        s += to_string(x);
    }
    cout << (s.find("101") == string::npos ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
