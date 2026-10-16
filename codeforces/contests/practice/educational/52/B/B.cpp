#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            l[i] = 1 + (i ? l[i - 1] : 0);
        }
        else {
            l[i] = 0;
        }
    }
    vector<int> r(n);
    for (int i = n - 1;i >= 0; i--) {
        if (s[i] == 'G') {
            r[i] = 1 + (i < n - 1 ? r[i + 1] : 0);
        }
        else {
            r[i] = 0;
        }
    }
    int ans = *max_element(l.begin(), l.end());
    for (int i = 1; i < n; i++) {
        if (s[i] == 'S') {

        }
        ans = max()
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
