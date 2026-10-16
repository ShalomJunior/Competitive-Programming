#include <bits/stdc++.h>
using namespace std;

const int N = 4;
const string S = "1100";
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int q;
    cin >> q;
    set<int> ids;
    for (int i = 0; i + N <= n; i++) {
        if (s.substr(i, N) == S)
            ids.insert(i);
    }
    while (q--) {
        int j;
        char c;
        cin >> j >> c;
        j--;
        s[j] = c;
        for (int i = max(0, j - N); i + N <= n && i <= j + N; i++) {
            if (s.substr(i, N) != S) {
                ids.erase(i);
            }
            else {
                ids.insert(i);
            }
        }
        cout << (ids.empty() ? "NO" : "YES") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
