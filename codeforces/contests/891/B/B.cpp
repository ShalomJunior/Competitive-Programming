#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<bool> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = s[i] >= '5';
        if (i) vec[i] = vec[i] | vec[i - 1];
    }
    for (int i = n - 1; i >= 0;) {
        if (s[i] < '5') {
            if (vec[i]) s[i] = '0';
            else break;
            i--;
        }
        else {
            s[i] = '0';
            bool f = false;
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] != '9') {
                    int d = s[j] - '0';
                    s[j] = '0' + d + 1;
                    f = true;
                    i = j;
                    break;
                }
                else s[j] = '0';
            }
            if (!f) {
                s = "1" + s;
                break;
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