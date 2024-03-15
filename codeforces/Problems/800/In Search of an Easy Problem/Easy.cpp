#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int a; cin >> a;
        ans |= a;
    }
    (ans & 1) ? cout << "HARD\n" : cout << "EASY\n";
}