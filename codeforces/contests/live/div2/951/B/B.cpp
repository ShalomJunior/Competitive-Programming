#include <bits/stdc++.h>
using namespace std;

const int N = 32;
void solve() {
    int x, y;
    cin >> x >> y;
    int j = 0;
    while (j < N) {
        int mask = 1 << j;
        int a = x & mask;
        int b = y & mask;
        if (a != b) break;
        j++;
    }
    cout << (1 << j) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
