#include<bits/stdc++.h>
using namespace std;

const int N = 10;
void solve() {
    string s;
    cin >> s;
    int ans = 10;
    for (int i = 0; i < (1 << N); i++) {
        string t = s;
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (t[j] == '?') {
                t[j] = (i & mask ? '1' : '0');
            }
        }
        int a = 0;
        int b = 0;
        int x = N / 2;
        int y = N / 2;
        for (int k = 0; k < N; k++) {
            int d = t[k] - '0';
            k & 1 ? b += d : a += d;
            k & 1 ? y-- : x--;
            if (a + x < b || b + y < a) {
                ans = min(ans, k + 1);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}

