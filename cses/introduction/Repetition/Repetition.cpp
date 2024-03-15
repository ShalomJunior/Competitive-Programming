#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    char curr = s[0];
    int best = 1, temp = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == curr) temp++;
        else {
            temp = 1;
            curr = s[i];
        }
        best = max(best, temp);
    }
    cout << best << endl;
}