#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s[i]) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}