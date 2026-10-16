#include <bits/stdc++.h>
using namespace std;

const string S = "IT";
bool check(string s) {
    int n = s.length();
    for (int i = 0; i + 1 < n; i += 2) {
        if (s.substr(i, 2) != S) return false;
    }
    return n > 0 && n % 2 == 0;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool flag = s[0] == 'M' && s.back() == 'T';
    int j = 1;
    string t;
    while (j < n) {
        t = "";
        while (j < n && s[j] != 'M') {
            t += s[j];
            j++;
        }
        flag &= check(t);
        j++;
    }
    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
