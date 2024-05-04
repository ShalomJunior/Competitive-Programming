#include <bits/stdc++.h>

using namespace std;

vector<int> del(string s, char c) {
    int n = (int)s.size();
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        if (s[i] != c)idx.push_back(i);
    }
    return idx;
}

int done(string s, char c) {
    auto idx = del(s, c);
    int ans = 0;
    while ((int)idx.size()) {
        ans++;
        vector<char> temp;
        string t;
        int last = -2;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == c)t.push_back(s[i]);
            else {
                if (i - last < 2) {
                    t.push_back(s[i]);
                }
                else {
                    last = i;
                }
            }
        }
        s = t;
        idx = del(s, c);
    }
    return ans;
}

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    int ans = INT_MAX;
    set<char> let(s.begin(), s.end());
    for (char c : let) {
        ans = min(ans, done(s, c));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}