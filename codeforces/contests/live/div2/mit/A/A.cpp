#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n <= 5) {
        cout << "MIT time";
    }
    else {
        int cnt = 1;
        int j = 1;
        while (j * 5 < n) j *= 5, cnt++;
        cout << "MIT^" << cnt << " time";
    }
    cout << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
