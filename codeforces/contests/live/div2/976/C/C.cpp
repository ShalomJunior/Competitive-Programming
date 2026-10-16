#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 62;
void solve() {
    int b, c, d;
    cin >> b >> c >> d;
    int a = 0;
    for (int j = 0; j < N; j++) {
        int mask = 1LL << j;
        int bb = b & mask;
        int cc = c & mask;
        int dd = d & mask;
        bool flag = false;
        for (int bit : {0LL, mask}) {
            if ((bit | bb) - (bit & cc) == dd) {
                a += bit;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            return;
        }
    }
    cout << a << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
