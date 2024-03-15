#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    long long n; cin >> n;
    string s = to_string(n);
    int m = s.length();
    int ans = INF;
    for (int i = m - 1; i >= 0; i--) {
        int curr = 0;
        if (s[i] == '0') {
            curr += m - 1 - i;
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '0') {
                    int d = (j < i ? m - 2 - j : m - 1 - j);
                    int sub = 0;
                    for (int k = 0; k < m; k++) {
                        if (k != i && k != j && s[k] != '0') {
                            cout << "#" << endl;
                            if (k > i) sub--;
                            if (k > j) sub--;
                            ans = min(ans, curr + d + k + sub);
                        }
                    }
                    break;
                }
            }
            for (int j = m - 1; j >= 0; j--) {
                if (s[j] == '5') {
                    int d = (j < i ? m - 2 - j : m - 1 - j);
                    int sub = 0;
                    for (int k = 0; k < m; k++) {
                        if (k != i && k != j && s[k] != '0') {
                            cout << "#2" << endl;
                            if (k > i) sub--;
                            if (k > j) sub--;
                            ans = min(ans, curr + d + k + sub);
                        }
                    }
                    ans = min(ans, curr + d);
                    break;
                }
            }
            break;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        int curr = 0;
        if (s[i] == '5') {
            curr += m - 1 - i;
            for (int j = m - 1; j >= 0; j--) {
                if (s[j] == '2') {
                    int d = (j < i ? m - 2 - j : m - 1 - j);
                    int sub = 0;
                    for (int k = 0; k < m; k++) {
                        if (k != i && k != j && s[k] != '0') {
                            cout << "{}1" << endl;
                            if (k > i) sub--;
                            if (k > j) sub--;
                            ans = min(ans, curr + d + k + sub);
                        }
                    }
                    break;
                }
            }
            for (int j = m - 1; j >= 0; j--) {
                if (s[j] == '7') {
                    int d = (j < i ? m - 2 - j : m - 1 - j);
                    int sub = 0;
                    for (int k = 0; k < m; k++) {
                        if (k != i && k != j && s[k] != '0') {
                            cout << "{}" << endl;
                            if (k > i) sub--;
                            if (k > j) sub--;
                            ans = min(ans, curr + d + k + sub);
                        }
                    }
                    break;
                }
            }
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}