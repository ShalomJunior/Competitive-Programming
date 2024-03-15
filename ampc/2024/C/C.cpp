#include <bits/stdc++.h>
using namespace std;

const int N = 5;
vector<int> a(N, 10);
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (s == "0") {
        cout << 0 << endl;
        return;
    }
    if (n > 1 && s[0] == '0') {
        cout << 0 << endl;
        return;
    }
    int p = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?') p *= a[i];
        else p *= 1;
    }
    cout << p << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a[0] = 9;
    int t; cin >> t;
    while (t--) solve();
}
