#include <bits/stdc++.h>
using namespace std;

int p[2][10];
bool prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = p[0][a + 1 - c] * pow(10, c - 1);
    int y = p[1][b + 1 - c] * pow(10, c - 1);
    cout << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 9; i++) {
        int cnt = 0;
        for (int j = pow(10, i); ; j++) {
            if (prime(j)) {
                p[cnt][i + 1] = j;
                if (++cnt == 2) break;
            }
        }
    }
    int t; cin >> t;
    while (t--) solve();
}