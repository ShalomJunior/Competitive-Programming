#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int cn = 0;
    for (auto& c : s)
        (c == '4' || c == '7') ? cn++ : cn;

    if (cn == 4 || cn == 7) cout << "YES\n";
    else cout << "NO\n";
}