#include <bits/stdc++.h>

using namespace std;

int main() {
    string line; getline(cin, line);
    char ans; int mx = 0;
    unordered_map<char, int> mp;
    for (auto& c : line) {
        if (c != ' ') {
            mp[c]++;
            if (mx < mp[c]) {
                mx = mp[c];
                ans = c;
            }
        }
    }
    cout << ans << endl;
}