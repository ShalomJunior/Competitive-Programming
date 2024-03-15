#include <bits/stdc++.h>
using namespace std;

map<string, int> ans;

void prepare() {
    for (char c = 'a'; c <= 'z'; c++) {
        for (char t = 'a'; t <= 'z'; t++) {
            if (c == t)continue;
            string s; s += c; s += t;
            ans[s] = 1 + ans.size();
        }
    }
}

void solve() {
    string s; cin >> s;
    cout << ans[s] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}