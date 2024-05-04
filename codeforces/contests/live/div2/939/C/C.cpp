#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int mx = n * (n + 1) / 2;
    int op = 0;
    stringstream ss;
    bool b = true;
    while (b) {
        b = false;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) s += a[i][j];
            if (s <= mx && op < 2 * n) {
                b = true;
                op++;
                ss << 1 << " ";
                ss << i + 1 << " ";
                for (int j = 0; j < n; j++) {
                    a[i][j] = j + 1;
                    ss << a[i][j] << " ";
                }
                ss << endl;
            }
        }
        for (int j = 0; j < n; j++) {
            int s = 0;
            for (int i = 0; i < n; i++) s += a[i][j];
            if (s <= mx && op < 2 * n) {
                b = true;
                op++;
                ss << 2 << " ";
                ss << j + 1 << " ";
                for (int i = 0; i < n; i++) {
                    a[i][j] = i + 1;
                    ss << a[i][j] << " ";
                }
                ss << endl;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
            cerr << a[i][j] << " ";
        }
        cerr << endl;
    }
    //cout << sum << " " << op << endl;
    //cout << ss.str() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
