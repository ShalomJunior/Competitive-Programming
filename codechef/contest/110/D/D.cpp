#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 1000;
    for (int i = 0; i < a; i++) {
        if (a - i < b) break;
        if ((a - i) % (b + i) == 0) {
            ans = min(ans, i);
            break;
        }
    }
    for (int i = 0; i < b; i++) {
        if (a + i < b - i) continue;
        if ((a + i) % (b - i) == 0) {
            ans = min(ans, i);
            break;
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