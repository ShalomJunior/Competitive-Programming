#include <bits/stdc++.h>
using namespace std;

string match = "vika";
void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    int id = 0;
    for (auto& c : a) cin >> c;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i][j] == match[id]) {
                id++;
                if (id == 4) {
                    cout << "YES" << endl;
                    return;
                }
                else break;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}