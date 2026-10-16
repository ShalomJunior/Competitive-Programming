#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int x;
    cin >> x;
    int cnt = __builtin_popcount(x);
    if (cnt == 1) {
        cout << (x == 1 ? 3 : x + 1);
    }
    else {
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (x & mask) {
                cout << mask;
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}