#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        if (n & 1)  cout << "NO" << endl;
        else {
            if (s.substr(0, n / 2) == s.substr(n / 2, n + 1)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}