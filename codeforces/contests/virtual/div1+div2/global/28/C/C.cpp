#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    string ans('0', n);
    int l1 = 0, r1 = n - 1;
    int l2 = 0, r2 = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        string p = s;
        for (int j = i; j >= 0; j--) {
            int k = i - j;
            if (p[n - 1 - k] != s[j]) {
                p[n - 1 - k] = '1';
            }
        }
    }
    cout << l1 << " " << r1 << endl;
    cout << l2 << " " << r2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}