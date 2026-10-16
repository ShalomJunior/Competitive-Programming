#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= k) g += x;
        else if (x == 0) {
            if (g) {
                cnt++;
                g--;
            }
        }
        else {}
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}