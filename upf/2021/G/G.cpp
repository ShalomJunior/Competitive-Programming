#include <bits/stdc++.h>

using namespace std;

int series(int n) {
    string s = to_string(n);
    int ans = 0;
    for (auto& c : s) {
        int dig = c - '0';
        ans += dig * dig;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    unordered_set<int> s = { 4, 16, 37, 58, 89, 145, 42, 20 };

    while (s.find(n) == s.end()) {
        n = series(n);
        if (n == 1) {
            cout << "special" << endl;
            return 0;
        }
    }
    cout << "normal" << endl;
}