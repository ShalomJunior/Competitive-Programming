#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    if (s[0] < s[1]) swap(s[0], s[1]);
    if (t[0] > t[1]) swap(t[0], t[1]);
    int a = stoi(s);
    int b = stoi(t);
    cout << (a > b ? "Yes" : "No") << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}