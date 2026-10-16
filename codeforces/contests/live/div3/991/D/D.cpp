#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && s[j] > '0'; j--) {
            if (s[j - 1] < s[j] - 1) {
                s[j]--;
                swap(s[j - 1], s[j]);
            }
            else break;
        }
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
