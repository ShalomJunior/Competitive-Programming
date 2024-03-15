#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b; string s;
    cin >> a >> b >> s;

    string ans;
    for (auto& c : s) {
        int id = c - 'a' + 1;
        int match = (a * id + b) % 26;
        char t = (!match) ? 'z' : 'a' + match - 1;
        cout << t;
    }
    cout << endl;
}