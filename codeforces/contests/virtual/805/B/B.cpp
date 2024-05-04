#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str; cin >> str;
    int ans = 0;
    set<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (s.size() == 3 && !s.count(str[i])) {
            ans++;
            s.clear();
        }
        s.insert(str[i]);
    }
    cout << ans + (s.size() != 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}