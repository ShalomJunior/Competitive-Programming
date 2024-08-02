#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a * b * c;
    for (int da = 0; da <= 5; da++) {
        for (int db = 0; db <= 5; db++) {
            for (int dc = 0; dc <= 5; dc++) {
                if (da + db + dc <= 5) {
                    ans = max(ans, (a + da) * (b + db) * (c + dc));
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}