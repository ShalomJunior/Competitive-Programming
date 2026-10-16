#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (auto& c : s) {
        if (c == 'w') cout << c;
        else {
            cout << (c == 'p' ? 'q' : 'p');
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}