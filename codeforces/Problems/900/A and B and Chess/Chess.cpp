#include <bits/stdc++.h>

using namespace std;

int main() {

    unordered_map<char, int>white, black;
    white['Q'] = 9; black['q'] = 9;
    white['R'] = 5; black['r'] = 5;
    white['B'] = 3; black['b'] = 3;
    white['N'] = 3; black['n'] = 3;
    white['P'] = 1; black['p'] = 1;

    int wh = 0, bl = 0;
    for (int i = 0; i < 8; i++) {
        string s; cin >> s;
        for (auto& c : s) {
            if (white.find(c) != white.end()) wh += white[c];
            else if (black.find(c) != black.end()) bl += black[c];
        }
    }

    if (wh > bl) cout << "White" << endl;
    else if (wh == bl) cout << "Draw" << endl;
    else cout << "Black" << endl;
}