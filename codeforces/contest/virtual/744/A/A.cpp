#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int a = 0, b = 0, c = 0;
    for (auto& ch : s) {
        if (ch == 'A') a++;
        else if (ch == 'B') b++;
        else c++;
    }
    cout << (a + c == b ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}