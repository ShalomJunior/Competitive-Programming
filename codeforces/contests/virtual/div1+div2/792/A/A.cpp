#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (n == 2) {
        cout << s.back();
    }
    else {
        sort(s.begin(), s.end());
        cout << s[0];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}