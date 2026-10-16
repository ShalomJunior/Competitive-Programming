#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> stk;
    for (auto& c : s) {
        if (c == '(') stk.push(c);
        else {
            if (stk.empty()) return false;
            else stk.pop();
        }
    }
    return stk.empty();
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = count(s.begin(), s.end(), '1');
    if (cnt & 1) {
        cout << "NO" << endl;
        return;
    }
    string a(n, '.');
    string b(n, '.');
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == '0') {
            if (j) {
                a[i] = ')';
                b[i] = '(';
            }
            else {
                a[i] = '(';
                b[i] = ')';
            }
            j ^= 1;
        }
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == '1') {
            j++;
            if (j <= cnt / 2) {
                a[i] = b[i] = '(';
            }
            else {
                a[i] = b[i] = ')';
            }
        }
    }
    if (check(a) && check(b)) {
        cout << "YES" << endl;
        cout << a << endl;
        cout << b << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
