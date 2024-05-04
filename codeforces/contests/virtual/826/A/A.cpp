#include <bits/stdc++.h>

using namespace std;

int cx(string s) {
    int ans = 0;
    int i = 0;
    while (s[i++] == 'X')ans++;
    return ans;
}

char in(string s) {
    if (s.find('S') != -1)return 'S';
    if (s.find('M') != -1)return 'M';
    if (s.find('L') != -1)return 'L';
    return ' ';
}

void solve() {
    string a, b; cin >> a >> b;
    char ia = in(a), ib = in(b);
    if (ia != ib) {
        cout << ((ia < ib) ? ">" : "<") << endl;
    }
    else {
        int ca = cx(a), cb = cx(b);
        if (ia == 'M' || ca == cb) {
            cout << "=" << endl;
        }
        else {
            if (ia == 'S') {
                cout << ((ca < cb) ? ">" : "<") << endl;
            }
            else {
                cout << ((ca < cb) ? "<" : ">") << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}