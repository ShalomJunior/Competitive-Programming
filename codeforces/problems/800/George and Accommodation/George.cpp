#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int p, q;
    int ans = 0;
    while (n--) {
        cin >> p >> q;
        (q - p >= 2) ? ans++ : ans;
    }
    cout << ans << endl;
}