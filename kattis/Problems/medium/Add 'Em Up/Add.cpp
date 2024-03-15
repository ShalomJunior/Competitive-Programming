#include <bits/stdc++.h>

using namespace std;

char mat(char c) {
    if (c == '6') return '9';
    else if (c == '9') return '6';
    return c;
}

int rev(int x) {
    string s = to_string(x);
    bool b = s.find(7) != -1;
    b |= (s.find(4) != -1);
    b |= (s.find(3) != -1);
    if (b) return -1;
    string ans;
    for (auto c : s) ans += mat(c);
    reverse(ans.begin(), ans.end());
    return stoi(ans);
}

int main() {
    int n, s; cin >> n >> s;
    unordered_multiset<int> ums, umsrev;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int b = rev(a);
        ums.insert(a);
        if (b != -1) umsrev.insert(b);
    }


    for (auto it = ums.begin(); it != ums.end();++it) {
        int fd = s - *it;
        if (ums.count(fd)) {
            if (fd != *it) {
                cout << "YES" << endl;
                return;
            }
            else {
                if (ums.count(fd) > 1) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }

        if (umsrev.count(fd)) {
            if (fd != *it) {
                cout << "YES" << endl;
                return;
            }
            else {
                if (umsrev.count(fd) > 1) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        fd = rev(fd);
        if ()
    }
}