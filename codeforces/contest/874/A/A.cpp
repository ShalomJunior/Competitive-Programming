#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<string> ans;
    for (int i = 0; i < n - 1; i++)
        ans.insert(s.substr(i, 2));
    cout << ans.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}