
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i - 1 < 0 || (i - 1 >= 0 && s[i - 1] == '0')) {
                s[i] = '0';
            }
            else {
                bool b = false;
                int j = i;
                while (j < n && s[j] == '?')j++;
                if (j == n) {
                    for (int k = i; k < n; k++)s[k] = '1';
                }
                else {
                    for (int k = i; k < j; k++) {
                        s[k] = ((s[j] == '1') ? '1' : '0');
                    }
                }
            }
        }
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

