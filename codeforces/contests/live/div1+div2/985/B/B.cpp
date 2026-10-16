#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, r;
    cin >> n >> s >> r;
    int x = count(s.begin(), s.end(), '0');
    int y = n - x;
    for (int i = 0; i < n - 1; i++) {
        if (min(x, y) == 0) {
            cout << "NO" << endl;
            return;
        }
        r[i] == '0' ? y-- : x--;
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
