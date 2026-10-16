#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        tot += c;
    }
    if (tot <= s && (s - tot) % x == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}