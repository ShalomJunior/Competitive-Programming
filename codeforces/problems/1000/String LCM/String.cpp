#include <bits/stdc++.h>

using namespace std;

string time(string s, int n) {
    string ans;
    while (n--) {
        ans += s;
    }
    return ans;
}
void solve() {
    string s, t; cin >> s >> t;
    int ls = s.length(), lt = t.length();
    if (ls < lt) {
        swap(s, t);
        swap(ls, lt);
    }

    int sz = lcm(ls, lt);
    string m = time(s, sz / ls);
    for (int i = 0; i < sz; i += lt) {
        if (m.substr(i, lt) != t) {
            cout << -1 << endl;
            return;
        }
    }
    cout << m << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}