#include <bits/stdc++.h>
using namespace std;

char f(char c, int a, int b) {
    int n = c - 'a' + 1;
    n = n * a + b;
    n %= 26;
    return (!n) ? 'z' : 'a' + n - 1;
}

int main() {
    int a, b; string s;
    cin >> a >> b >> s;
    string ans;
    for (auto& c : s)ans.push_back(f(c, a, b));
    cout << ans << endl;
}