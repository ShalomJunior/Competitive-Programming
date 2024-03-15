#include <bits/stdc++.h>
using namespace std;

int main() {
    set<char> in = { '(', '{', '[' };
    unordered_map<char, char> f;
    f[')'] = '('; f['}'] = '{'; f[']'] = '[';
    string str; cin >> str;
    cout << str << endl;
    stack<char> s;
    for (auto& c : str) {
        if (in.count(c)) s.push(c);
        else {
            if (s.empty() || s.top() != f[c]) {
                cout << "invalide" << endl;
                return 0;
            }
            else s.pop();
        }
    }
    cout << ((s.empty() ? "valide" : "invalide")) << endl;
}