#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    stack<char> st;
    set<char> open = { '[', '<', '{' , '(' };
    int mis = 0;
    for (int i = 0; i < n; i++) {
        if (open.count(s[i])) st.push(s[i]);
        else {
            if (st.empty()) {
                cout << "Impossible" << endl;
                return;
            }
            else {
                if (s[i] == '>' && st.top() != '<') mis++;
                if (s[i] == ']' && st.top() != '[') mis++;
                if (s[i] == '}' && st.top() != '{') mis++;
                if (s[i] == ')' && st.top() != '(') mis++;
                st.pop();
            }
        }
    }
    if (st.empty()) cout << mis;
    else cout << "Impossible";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
