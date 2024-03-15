#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h; cin >> n >> h;
    int ans = 0;
    while (n--) {
        int v; cin >> v;
        (v > h) ? ans += 2 : ans++;
    }
    cout << ans << endl;

}