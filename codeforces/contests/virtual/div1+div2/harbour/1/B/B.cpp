#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int a = s.length();
    int b = t.length();
    for (int i = 0; i < a; i++) {
        for (int j = i; j < a; j++) {
            int x = j - i + 1;
            int y = j;
            if (x > b || x + y < b) continue;
            if (s.substr(i, x) == t.substr(0, x)) {
                bool flag = true;
                for (int k = j - 1; k >= 0 && x - 1 + j - k < b; k--) {
                    flag &= s[k] == t[x - 1 + j - k];
                }
                if (flag) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}