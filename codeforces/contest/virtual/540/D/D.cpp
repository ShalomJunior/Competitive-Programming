#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int bad = 0, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt++;
        if (s[i] != s[i - 1]) {
            if (cnt > 1) {
                for (int j = i - 2; j >= i - cnt; j -= 2) {
                    set<char> let = { 'R', 'G', 'B' };
                    let.erase(s[j + 1]);
                    if (j) let.erase(s[j - 1]);
                    s[j] = *let.begin();
                    bad++;
                }
            }
            cnt = 1;
        }
    }
    if (cnt > 1) {
        for (int j = n - 2; j >= n - cnt; j -= 2) {
            set<char> let = { 'R', 'G', 'B' };
            let.erase(s[j + 1]);
            if (j) let.erase(s[j - 1]);
            s[j] = *let.begin();
            bad++;
        }
    }
    cout << bad << endl;
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}