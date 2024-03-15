#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    queue<int> e, o;
    for (int i = 1; i < n * n; i++) {
        i & 1 ? o.push(i) : e.push(i);
    }
    int ans[n][n];
    ans[0][0] = 1; o.pop();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) {
                if (e.empty()) {
                    cout << -1 << endl;
                    return;
                }
                ans[i][j] = e.front();
                e.pop();
            }
            else {
                if (o.size() >= 2) {
                    ans[i][j] = o.front();
                    o.pop();
                    ans[j][i] = o.front();
                    o.pop();
                }
                else if (e.size() >= 2) {
                    ans[i][j] = e.front();
                    e.pop();
                    ans[j][i] = e.front();
                    .pop();
                }
                else {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
