#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> a;
void init() {
    for (int i = 1; i < N; i++) {
        int x = i;
        bool flag = true;
        while (x) {
            if (x % 10 > 1) {
                flag = false;
                break;
            }
            x /= 10;
        }
        if (flag)a.push_back(i);
    }
}

void solve() {
    int n;
    cin >> n;
    bool ans = false;
    function<void(int n)> go = [&](int x) {
        if (x == 1) {
            ans = true;
            return;
        }
        if (!ans) {
            for (auto& c : a) {
                if (c != 1 && x % c == 0) go(x / c);
            }
        }
        };
    go(n);
    cout << (ans ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--)solve();
}