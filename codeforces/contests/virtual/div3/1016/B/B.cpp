#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int j = n - 1;
    int cnt = 0;
    while (j >= 0 && s[j] == '0') {
        cnt++;
        j--;
    }
    j--;
    while (j >= 0) {
        if (s[j] != '0') cnt++;
        j--;
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}