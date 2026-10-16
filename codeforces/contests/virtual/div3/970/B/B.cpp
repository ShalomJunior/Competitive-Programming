#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = count(s.begin(), s.end(), '1');
    int k = sqrt(n);
    if (k * k != n || cnt != 4 * (k - 1)) {
        cout << "NO" << endl;
        return;
    }
    else {
        cout << "YES";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}