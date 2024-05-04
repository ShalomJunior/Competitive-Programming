#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    for (auto& c : s)c = tolower(c);
    cout << ((s == "yes") ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}