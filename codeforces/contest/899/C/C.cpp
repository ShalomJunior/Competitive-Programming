#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int card[N][N];
void solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            if (c == 'X') ans += card[i][j];
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < N / 2; i++) {
        for (int x = i; x < N - i; x++) {
            for (int y = i; y < N - i; y++) {
                card[x][y] = i + 1;
                card[y][x] = i + 1;
            }
        }

    }
    int t; cin >> t;
    while (t--)solve();
}
