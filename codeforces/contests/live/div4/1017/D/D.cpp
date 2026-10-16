#include <bits/stdc++.h>
using namespace std;

void solve() {
    string p, s;
    cin >> p >> s;
    while (!p.empty() && !s.empty()) {
        char c = p.back();
        int x = 0;
        while (!p.empty() && p.back() == c) {
            p.pop_back();
            x++;
        }
        int y = 0;
        while (!s.empty() && s.back() == c) {
            s.pop_back();
            y++;
        }
        if (x <= y && y <= 2 * x) {}
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << (!p.empty() || !s.empty() ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
