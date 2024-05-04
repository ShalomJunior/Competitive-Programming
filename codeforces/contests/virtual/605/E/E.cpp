#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans[n][2];
    bool vis[n][2];
    for (int i = 0; i < n; i++) {
        ans[i][0] = ans[i][1] = INF;
        vis[i][0] = vis[i][1] = false;
    }
    function<int(int, int, bool)> go = [&](int i, int p, bool root) {
        if (i == 76 && p == 1) {
            cout << "in" << endl;
        }
        if (!root && (a[i] % 2) == p) {
            if (i == 76 && p == 1)
                cout << "leaving" << endl;
            return 0;
        }
        if (vis[i][p]) return ans[i][p];
        if (i == 76 && p == 1) {
            cout << "still" << endl;
        }
        vis[i][p] = true;
        int val = INF;
        if (i == 84) {
            cout << "i = " << i << " " << p << endl;
            cout << "->" << a[i] << endl;
            cout << "val = " << val << endl;
        }
        if (i + a[i] < n) {
            val = min(val, go(i + a[i], p, false));
            if (i == 84) {
                cout << "trying " << p << endl;
                cout << "val = " << val << endl;
            }
        }
        if (0 <= i - a[i]) {
            val = min(val, go(i - a[i], p, false));
            if (i == 84) {
                cout << "-->" << go(i - a[i], p, false) << endl;
                cout << "trying#### " << p << endl;
                cout << i - a[i] << endl;
                cout << ans[i - a[i]][p] << endl;
                cout << "val = " << val << endl;
            }
        }
        if (i == 84 || i == 76 || i == 68) {
            cout << "i = " << i << " " << p << endl;
            cout << "->" << a[i] << endl;
            cout << "val = " << val << endl;
        }
        cout << "WANTING " << ans[76][1] << endl;
        ans[i][p] = (val == INF ? INF : 1 + val);
        if (i == 76 && p == 1) cout << "--->" << ans[i][p] << endl;
        if (i == 76 && p == 1) {
            cout << "Quiting" << endl;
        }
        if (i == 84 && p == 1) {
            cout << "WE HAVE FINFISHED" << endl;
        }


        return ans[i][p];
        };
    for (int i = 0; i < n; i++) {
        if (!vis[i][(a[i] + 1) % 2])
            go(i, (a[i] + 1) % 2, true);
        int x = ans[i][(a[i] + 1) % 2];
        //cout << (x == INF ? -1 : x) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}