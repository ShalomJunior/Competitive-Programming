#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    int z = 0;
    while (true) {
        n = s.length();
        bool flag = false;
        for (int i = z; i < n; i++) {
            if (i == k) {
                cout << s.substr(0, k) << endl;
                return;
            }
            for (int j = 0; i + j < n; j++) {
                if (s[i + j] < s[j]) {
                    break;
                }
                if (s[j] < s[i + j]) {
                    s = s.substr(0, i + j) + s[j];
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) s += s;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}