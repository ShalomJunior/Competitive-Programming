#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    set<int> del;
    for (int i = 0, p = 0; i < n; i++) {
        if (i % 2 == p % 2 && i + 1 < n) {
            if (s[i] == s[i + 1]) {
                for (int j = i + 1; j < n; j++, i++) {
                    if (s[j] != s[i]) break;
                    del.insert(j);
                    p = (p + 1) % 2;
                }
            }
        }
    }
    string ans;
    for (int i = 0; i < n; i++) {
        if (!del.count(i)) ans += s[i];
    }
    int moves = del.size();
    if (ans.length() & 1) {
        moves++;
        ans.pop_back();
    }
    cout << moves << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}