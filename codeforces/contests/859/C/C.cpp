#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    unordered_map <char, int> mp;
    string ans;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (mp.find(c) == mp.end()) {
            if (mp[s[i - 1]] == '0')mp[c] = '1';
            else mp[c] = '0';
        }
        ans += mp[c];
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == ans[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}