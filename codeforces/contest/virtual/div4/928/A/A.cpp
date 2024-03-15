#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int x = count(s.begin(), s.end(), 'A');
    cout << (x > 2 ? "A" : "B") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}