#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        if (n % i)continue;
        string t = s.substr(0, i);
        reverse(t.begin(), t.end());
        s = t + s.substr(i, n - i);
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}