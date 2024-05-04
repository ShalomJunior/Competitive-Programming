#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;
        if (t[i] == 'a') {
            cout << "NO" << endl;
            return;
        }
        else if (t[i] == 'b') {
            int j = i;
            while (j < n && s[j] == 'a') j++;
            if (j == n || s[j] == 'c') {
                cout << "NO" << endl;
                return;
            }
            swap(s[i], s[j]);
        }
        else {
            int j = i;
            while (j < n && s[j] == 'b') j++;
            if (j == n || s[j] == 'a') {
                cout << "NO" << endl;
                return;
            }
            swap(s[i], s[j]);
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
