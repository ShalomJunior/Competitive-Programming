#include <bits/stdc++.h>
using namespace std;

const int N = 20;
void solve() {
    int a, b; cin >> a >> b;
    int x = 1, y = 1;
    for (int last, j = N; j >= 0; j--) {
        int mask = 1 << j;
        if ((a & mask) && !(b & mask)) {
            int m = (1 << (j + 1)) - 1;
            x = (1 << last) - (a & ((1 << (last + 1)) - 1));
            if (b != a + x) x++;
            y = (a & m) - (b & m) + 1;
            break;
        }
        if (!(a & mask) && (b & mask)) last = j;
    }
    int z = 1 + (a | b) - b;
    cout << min({ x, y, z }) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int j = 1 << 4;
    int t; cin >> t;
    while (t--)solve();
}