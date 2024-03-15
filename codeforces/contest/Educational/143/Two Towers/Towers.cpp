#include <bits/stdc++.h>

using namespace std;

bool done(string& s1, string& s2) {
    for (int j = s1.length() - 1; j > 0; --j) {
        if (s1[j] == s1[j - 1]) {
            if (s1[s1.length() - 1] == s2[s2.length() - 1]) {
                cout << "NO" << endl;
                return true;
            }
            string temp = s1.substr(j, s1.length() - 1);
            reverse(temp.begin(), temp.end());
            s2 += temp;
            s1 = s1.substr(0, j);
        }
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;

    string s1, s2; cin >> s1 >> s2;

    if (done(s1, s2)) return;
    if (done(s2, s1)) return;
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}