#include <bits/stdc++.h>
using namespace std;

const int N = 6;
void solve() {
    string s; cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        (i < 3) ? a += (s[i] - '0') : b += (s[i] - '0');
    }
    cout << ((a == b) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}