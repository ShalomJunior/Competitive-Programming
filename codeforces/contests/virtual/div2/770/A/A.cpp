#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    if (isPalindrome(s)) {
        cout << 1 << endl;
        return;
    }
    cout << (k ? 2 : 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}