#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P')a++;
        else if (s[i] == 'R')b++;
        else c++;
    }
    string ans;
    if (a >= max(b, c))cout << string(n, 'S');
    else if (b >= max(a, c))cout << string(n, 'P');
    else cout << string(n, 'R');
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
