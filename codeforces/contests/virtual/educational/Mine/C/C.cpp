#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') cnt++;
        else cnt--;
        if (cnt < 0) {
            cout << "invalid" << endl;
            return;
        }
    }
    cout << (cnt ? "invalid" : "valid") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
