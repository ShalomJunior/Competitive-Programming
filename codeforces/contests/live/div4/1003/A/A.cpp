#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    s.pop_back();
    s.pop_back();
    s += "i";
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
