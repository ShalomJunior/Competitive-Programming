#include <bits/stdc++.h>
using namespace std;

string f(string& s) {
    string ans = "";
    int cnt = 0;
    char c = s[0];
    while (s.size() && s[0] == c) { cnt++; s = s.substr(1, s.size() - 1); }
    ans += to_string(cnt) + c;
    return ans;
}

string h(string s) {
    string ans = "";
    while (s.size()) ans += f(s);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s = "1";
    for (int i = 2; i <= n; i++) {
        s = h(s);
    }
    cout << s << endl;
}