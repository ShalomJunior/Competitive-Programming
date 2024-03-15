#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (count(s.begin(), s.end(), 'B') == 0) cout << 0;
    else {
        int l = 0, r = n - 1;
        while (s[l] != 'B')l++;
        while (s[r] != 'B')r--;
        cout << (r - l + 1);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
