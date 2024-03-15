#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string _, s;
    getline(cin, _);
    getline(cin, s);
    int n = s.length();
    string a, b;
    for (int i = 0; i < N; i++)a += 'a' + i;
    b = a;
    reverse(b.begin(), b.end());
    cout << a << endl;
    cout << b << endl;
    string ans;
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            ans += b[s[i] - 'a'];
        }
        else {
            ans += s[i];
        }
    }
    cout << "ans = " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}