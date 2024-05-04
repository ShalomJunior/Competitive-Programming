#include <bits/stdc++.h>
using namespace std;

const int P = 300;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n & 1) {
        cout << -1 << endl;
        return;
    }
    bool flag = true;
    int p = 0;
    stringstream ss;
    while (flag) {
        flag = false;
        int m = s.size();
        for (int i = 0; i < m / 2; i++) {
            if (s[i] == s[m - 1 - i]) {
                if (p == P) {
                    cout << -1 << endl;
                    return;
                }
                p++;
                if (s[i] == '0') {
                    ss << m - i << " ";
                    s = s.substr(0, m - i) + "01" + s.substr(m - i, i);
                }
                else {
                    ss << i << " ";
                    s = s.substr(0, i) + "01" + s.substr(i, m - i);
                }
                flag = true;
                break;
            }
        }
    }
    cout << p << endl;
    cout << ss.str() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}