#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    string s; cin >> s;

    unordered_map<int, char> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(a[i]) != mp.end()) {
            if (mp[a[i]] != s[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            mp[a[i]] = s[i];
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}