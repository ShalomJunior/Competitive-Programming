#include<bits/stdc++.h>
using namespace std;

void solve() {
    int r, h;
    cin >> r >> h;
    int ans = 2 * (h / r);
    double rem = h % r;
    double mn = r * sqrt(3) / 2;
    if (rem >= mn) {
        ans += 3;
    }
    else if (rem * 2 >= r) {
        ans += 2;
    }
    else {
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}