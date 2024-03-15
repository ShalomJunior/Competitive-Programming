#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    long long n; cin >> n;
    string s = to_string(n);
    int m = s.length();
    int ans = INF;
    auto go = [&](char c, int i) {
        int curr = m - 1 - i;
        for (int j = m - 1; j >= 0; j--) {
            if (i != j && s[j] == c) {
                int d = (j < i ? m - 2 - j : m - 1 - j);
                if (m == 2) ans = min(ans, curr + d);
                else {
                    int sub = 0;
                    for (int k = 0; k < m; k++) {
                        if (k != i && k != j && s[k] != '0') {
                            if (k > i) sub--;
                            if (k > j) sub--;
                            ans = min(ans, curr + d + k + sub);
                            break;
                        }
                    }
                }
                break;
            }
        }
        };
    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == '0') {
            go('0', i); go('5', i);
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == '5') {
            go('2', i); go('7', i);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}