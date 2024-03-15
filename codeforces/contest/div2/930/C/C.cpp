#include <bits/stdc++.h>
using namespace std;

char query(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    cout.flush();
    char ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (query(mx, mx, i, i) == '<') mx = i;
    }
    int mn = 0;
    for (int i = 0; i < n; i++) {
        if (i == mx) continue;
        char c = query(mx, mn, mx, i);
        if (c == '<') {
            mn = i;
        }
        else if (c == '=') {
            if (query(i, i, mn, mn) == '<')mn = i;
        }
    }
    cout << "! " << mn << " " << mx << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
