#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 2;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 100;
    string op;
    function<void(int, int, int, string)> go = [&](int x, int y, int id, string s) {
        if (id >= ans) return;
        if (x == y) {
            if (id < ans) {
                ans = id;
                op = s;
            }
            return;
        }
        if (x == 0) {
            int need = f(y);
            if (id + need < ans) {
                ans = id + need;
                op = s + string(need, '0');
            }
            return;
        }
        if (x % 2 == y % 2 || x % 2 == 0) {
            go(x / 2, y / 2, id + 1, s + "0");
        }
        else {
            go((x + 1) / 2, (y + 1) / 2, id + 1, s + "1");
        }
        };
    if (n == 1) {
        cout << 0 << endl;
    }
    else {
        go(a[0], a[n - 1], 0, "");
        cout << ans << endl;
        if (ans <= n) {
            for (auto& c : op) cout << c << " ";
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
