#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (k != 1 && n & 1) {
        cout << "NO" << endl;
        return;
    }
    queue<int> o, e;
    for (int i = 1; i <= n * k; i++) {
        i & 1 ? o.push(i) : e.push(i);
    }
    auto go = [&](queue<int>& q) {
        while (!q.empty()) {
            int j = 0;
            while (j < k) {
                cout << q.front() << " ";
                q.pop();
                j++;
            }
            cout << endl;
        }
        };
    cout << "YES" << endl;
    go(o), go(e);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}