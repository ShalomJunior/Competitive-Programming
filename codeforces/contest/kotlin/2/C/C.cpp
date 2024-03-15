#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int cnt = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '*') x++;
        else {
            cnt += max(x - 1, 0);
            x = 0;
        }
        if (b[i] == '*') y++;
        else {
            cnt += max(y - 1, 0);
            y = 0;
        }
    }
    cnt += max(0, x - 1) + max(0, y - 1);
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
