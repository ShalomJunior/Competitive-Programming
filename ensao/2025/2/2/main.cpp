#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s = "aaabbaabbaabba";
    string p = "abba";
    int n = s.length();
    int m = p.length();
    sort(p.begin(), p.end());
    if (m > 0 && n > 0) {
        for (int i = 0; i + m <= n; i++) {
            string t = s.substr(i, m);
            sort(t.begin(), t.end());
            if (t == p) {
                cout << i << " ";
            }
        }
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}