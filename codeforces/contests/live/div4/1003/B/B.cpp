#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int j = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            j = i;
        }
    }
    cout << (j == -1 ? n : 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
