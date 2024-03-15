#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    string r = s;
    reverse(r.begin(), r.end());
    int x = count(s.begin(), s.end(), '0');
    if (x == 0) cout << 0;
    else if (x == 1 || x == n) cout << 1;
    else {
        vector<int> id;
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') id.push_back(j);
        }
        bool b = true;
        for (int j = 1; j < id.size(); j++) {
            b &= id[j] == 1 + id[j - 1];
        }
        cout << (b ? 1 : 2);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}