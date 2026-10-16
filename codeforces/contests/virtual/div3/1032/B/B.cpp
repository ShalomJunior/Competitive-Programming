#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (auto c = 'a'; c <= 'z'; c++) {
        int cnt = count(s.begin(), s.end(), c);
        if (cnt > 1) {
            if (cnt > 2 || s[0] != c || s.back() != c) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}