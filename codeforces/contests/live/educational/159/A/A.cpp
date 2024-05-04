#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    sort(s.begin(), s.end());
    int cnt = count(s.begin(), s.end(), '0');
    if (cnt >= (n + 1) / 2 || s.find("01") != -1) {
        cout << "YES";
    }
    else cout << "NO";
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
