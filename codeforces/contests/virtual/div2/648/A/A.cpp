#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    set<int> r, c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j]) {
                r.insert(i);
                c.insert(j);
            }
        }
    }
    bool flag = true;
    while (true) {
        bool ok = false;
        for (int i = 0; !ok && i < n; i++) {
            for (int j = 0; !ok && j < m; j++) {
                if (!r.count(i) && !c.count(j)) {
                    ok = true;
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        if (!ok)break;
        flag = !flag;
    }
    cout << (flag ? "Vivek" : "Ashish") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

