#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3;
void solve() {
    vector<string> s(N);
    for (auto& str : s) cin >> str;
    int j;
    cin >> j;
    j--;
    auto g = s;
    for (int i = 0; i < N; i++) {
        if (i == j) {
            sort(g[i].begin(), g[i].end());
        }
        else {
            sort(g[i].rbegin(), g[i].rend());
        }
    }
    for (int i = 0; i < N; i++) {
        int a = stoll(i == 0 ? g[0] : s[0]);
        int b = stoll(i == 1 ? g[1] : s[1]);
        int c = stoll(i == 2 ? g[2] : s[2]);
        int mx = max({ a, b , c });
        if (j == 0) {
            if (mx > a) {
                cout << "YES" << endl;
                return;
            }
        }
        else if (j == 1) {
            if (mx > b) {
                cout << "YES" << endl;
                return;
            }
        }
        else if (j == 2) {
            if (mx > c) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}