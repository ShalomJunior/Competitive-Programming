#include <bits/stdc++.h>

using namespace std;

bool is_open(char c) {
    return (c == '(' || c == '[' || c == '{');
}

int main() {
    string s; cin >> s;
    stack<char> bf;
    for (auto& c : s) {
        if (is_open(c)) bf.push(c);
        else {
            if (bf.top() == c - 1 || bf.top() == c - 2) bf.pop();
            else {
                cout << "invalide" << endl;
                return 0;
            }
        }
    }
    cout << ((bf.empty()) ? "valide" : "invalide") << endl;
}