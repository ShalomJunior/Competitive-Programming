#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = count(s.begin(), s.end(), s[0]);
    if (cnt == n) {
        cout << "NO";
    }
    else {
        auto r = s;
        reverse(r.begin(), r.end());
        if (s < r) {
            cout << "YES";
        }
        else {
            cout << (k ? "YES" : "NO");
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
