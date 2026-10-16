#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int l = 0;
    while (l < n && s[l] != '[') l++;
    int r = n - 1;
    while (r >= 0 && s[r] != ']') r--;
    if (l > r) {
        cout << -1 << endl;
        return;
    }
    int i = l;
    while (i < r && s[i] != ':') i++;
    int j = r;
    while (j > l && s[j] != ':') j--;
    if (j <= i) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    for (int k = i; k < j; k++) cnt += s[k] == '|';
    cout << 4 + cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
