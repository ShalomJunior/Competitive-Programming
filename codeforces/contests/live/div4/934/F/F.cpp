#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ends = 1;
    int ans = 0;
    while (true) {
        int temp = 0;
        while (a && ends) {
            if (ends + temp == c || a == 0) break;
            a--;
            ends--;
            temp += 2;
        }
        if (temp) ans++;
        bool flag = (ends + temp == c);
        if (flag) {
            if (ends && ans) b -= min(b, ends);
            ans += (b + c - 1) / c;
            cout << (a ? -1 : ans) << endl;
            return;
        }
        if (a == 0) break;
        ends = temp;
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
