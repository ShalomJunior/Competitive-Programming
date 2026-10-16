#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int i = 0;
    while (i < n && s[i] != 'p') i++;
    int j = n - 1;
    while (j >= 0 && s[j] != 's') j--;
    if (i == n || j == -1) {
        cout << "YES" << endl;
        return;
    }
    if (i < j) {
        cout << "NO" << endl;
        return;
    }
    cout << (i == n - 1 || j == 0 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
