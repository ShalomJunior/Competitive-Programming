#include <bits/stdc++.h>

using namespace std;

const string str = "Timru";

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    sort(s.begin(), s.end());
    cout << ((str == s) ? "YES" : "NO") << endl;

}

int main() {
    int t; cin >> t;
    while (t--)solve();
}