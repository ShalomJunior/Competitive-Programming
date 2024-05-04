#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)cin >> p[i];
    int j = 1;
    while (p[j] != x)j++;
    int L = 1, R = n + 1;
    vector<int> moves;
    while (L + 1 < R) {
        int m = (L + R) / 2;
        if (p[m] <= x) {
            L = m;
            moves.push_back(L);
        }
        else R = m;
    }
    if (p[L] == x) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    int e = j;
    int f = moves.empty() ? L : moves.back();
    cout << e << " " << f << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

// swap(p[e], p[f]);
// L = 1, R = n + 1;
// while (L + 1 < R) {
//     int m = (L + R) / 2;
//     if (p[m] <= x) {
//         L = m;
//     }
//     else R = m;
// }
// assert(p[L] == x);