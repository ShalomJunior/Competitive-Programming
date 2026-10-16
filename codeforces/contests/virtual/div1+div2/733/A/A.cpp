#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    cout << *max_element(s.begin(), s.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}