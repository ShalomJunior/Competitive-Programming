#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    unordered_map<string, int> um;
    multiset<string> o, d, t;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int m = s[i].length();
        um[s[i]]++;
    }
    for (int i = 0; i < n; i++) {
        um[s[i]]--;
        string p = s[i];
        int m = p.length();
        reverse(p.begin(), p.end());
        if (um[p]) {
            cout << "YES" << endl;
            return;
        }
        if (m == 2) {
            if (um[to_string(p[0])]) {
                cout << "YES" << endl;
                return;
            }
        }
        if (m == 3) {
            string t = p.substr(1, 2);
            if (um[t] || (um[to_string(p[0])] && p[1] == p[2])) {
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
    while (t--) solve();
}