#include <bits/stdc++.h>
using namespace std;

const int N = 4;
const int M = 5000;
void solve() {
    int mx = M, Mx = -M, my = M, My = -M;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        mx = min(mx, x);
        Mx = max(Mx, x);
        my = min(my, y);
        My = max(My, y);
    }
    cout << (Mx - mx) * (My - my) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
