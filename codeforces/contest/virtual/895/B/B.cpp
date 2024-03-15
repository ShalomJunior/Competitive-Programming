#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    if (k & 1) {
        string o, e;
        for (int i = 0; i < n; i++) {
            i & 1 ? o += s[i] : e += s[i];
        }
        sort(e.rbegin(), e.rend());
        sort(o.rbegin(), o.rend());
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                cout << o.back();
                o.pop_back();
            }
            else {
                cout << e.back();
                e.pop_back();
            }
        }
        cout << endl;
    }
    else {
        sort(s.begin(), s.end());
        cout << s << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}