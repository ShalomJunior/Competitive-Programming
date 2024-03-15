#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;  getline(cin, s);
    unordered_map<char, int> m;
    int mx = 0;
    for (auto& c : s) {
        m[c]++;
        mx = max(mx, m[c]);
    }

    for (auto& [k, v] : m) {
        if (v == mx) {
            cout << k << endl;
            break;
        }
    }
}