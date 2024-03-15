#include <bits/stdc++.h>
using namespace std;

bool match(string s) {
    int n = s.size();
    stack<char> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')stk.push(s[i]);
        else {
            if (stk.empty() || (!stk.empty() && stk.top() == s[i])) return false;
            else stk.pop();
        }
    }
    return true;
}

void solve() {
    int n; string s; cin >> n >> s;
    int open = 0, close = 0;
    for (int i = 0; i < n; i++) {
        (s[i] == '(') ? open++ : close++;
    }
    if (open != close) { cout << "-1\n"; return; }
    string t = s; reverse(t.begin(), t.end());
    if (match(s) | match(t)) {
        cout << "1\n";
        while (n--)cout << "1 ";
        cout << endl;
        return;
    }
    cout << 2 << endl;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) { cout << ((s[i] == '(') ? 1 : 2) << " "; }
        else { cout << ((s[i] == '(') ? 2 : 1) << " "; }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

