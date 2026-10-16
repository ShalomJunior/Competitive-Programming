#include <bits/stdc++.h>
using namespace std;

const int N = 4;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    auto work = [&](string t, int z) {
        set<string> r;
        for (int i = 0; i < z; i++) {
            for (int j = i; j < z; j++) {
                r.insert(t.substr(i, j - i + 1));
            }
        }
        return r.size();
        };
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= N && i + j <= n; j++) {
            if (work(s.substr(i, j), j) % 2 == 0) {
                cout << s.substr(i, j) << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}