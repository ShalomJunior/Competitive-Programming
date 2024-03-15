#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        v[i] = c;
    }

    int ans = 0;
    int ones = 0;
    int free = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            ones++;
            if (free > 0) free--;
            else {
                ans++;
            }
        }
        else {
            if (ones <= 0)continue;
            if (ones % 2 == 0) {
                free += (ones / 2) - 1;
                ones = 2;
            }
            else {
                free += (ones - 1) / 2;
                ones = 1;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}