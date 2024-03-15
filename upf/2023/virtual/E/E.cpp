#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t; cin >> s >> t;
    int ls = s.size(), lt = t.size();
    reverse(t.begin(), t.end());
    if (ls < lt) { swap(s, t); swap(ls, lt); }
    string ans = "";
    for (int i = 0; i < lt; i++) {
        for (int j = 1; j <= lt - i; j++) {
            string match = t.substr(i, j);
            if (s.find(match) != -1 && ans.size() < match.size()) ans = match;
        }
    }
    cout << ans << endl;
}