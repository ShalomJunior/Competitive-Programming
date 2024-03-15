#include <bits/stdc++.h>

using namespace std;

string lead(string s) {
    return s.substr(1, s.length() - 1);
}

int main() {
    unordered_set<string> s;

    int ans = 0;
    string str;
    while (getline(cin, str)) {
        if (str[0] == '+')s.insert(lead(str));
        else if (str[0] == '-')s.erase(lead(str));
        else {
            ans += s.size() * (str.size() - 1 - str.find(":"));
        }
    }
    cout << ans << endl;
}