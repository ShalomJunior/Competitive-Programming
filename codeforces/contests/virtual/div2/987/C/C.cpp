#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1, -1);
    int last = 1;
    if (n & 1) {
        if (n < 27) {
            cout << -1 << endl;
            return;
        }
        p[1] = p[10] = p[26] = 1;
        p[11] = p[27] = 2;
        last = 3;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == -1) {
            p[i] = p[i + 1] = last++;
            i++;
        }
    }
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}